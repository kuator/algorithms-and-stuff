#include <bits/stdc++.h>
#include <ctime>
using namespace std; 

class Subset 
{ 
  public:
    int parent; 
    int rank; 
}; 

class WeightedQuickUnion {
  public:
    int find(int i);
    void unify(int x, int y );
    bool connected(int x, int y );
    int components;
    int V;
    ~WeightedQuickUnion();
    Subset* subsets;
};

WeightedQuickUnion::~WeightedQuickUnion(void){
  delete[] subsets;
}

int WeightedQuickUnion::find(int i){
  if (subsets[i].parent != i) {
    subsets[i].parent = find(subsets[i].parent);
  } 

  return subsets[i].parent;
}

bool WeightedQuickUnion::connected(int x, int y){
  return find(x) == find(y);
}

void WeightedQuickUnion::unify(int x, int y ){
  int xset = find(x);
  int yset = find(y);

  if(subsets[xset].rank > subsets[yset].rank) {
    subsets[yset].parent = xset;
    subsets[xset].rank += subsets[yset].rank;
  }
  else if (subsets[xset].rank < subsets[yset].rank) {
    subsets[xset].parent = yset;
    subsets[yset].rank += subsets[xset].rank;
  }
  else {
    subsets[xset].parent = yset;
    subsets[yset].rank += subsets[xset].rank;
  }
  components--;
}

WeightedQuickUnion* createWeightedQuickUnion(int V){
  WeightedQuickUnion* uf = new WeightedQuickUnion;
  uf->V = V;
  uf->subsets = new Subset[uf->V];
  uf->components = uf->V;
  for (int v = 0; v < uf->V; ++v) { 
    uf->subsets[v].parent = v; 
    uf->subsets[v].rank = 1; 
  } 
  return uf;
}


class Perculation{
  public:
    bool* dataSet;
    int lastIndex;
    int N; 
    ~Perculation();
    void open(int i, int j);
    void validate();
    bool isFull(int i, int j);
    bool percolates();
    int arrayIndex(int i, int j);
    bool isOpen(int i, int j);
    WeightedQuickUnion* percolatesUnionFind;
    WeightedQuickUnion* isFullUnionFind;
};

Perculation::~Perculation(void){
  delete percolatesUnionFind;
  delete isFullUnionFind;
  delete[] dataSet;
}

int Perculation::arrayIndex(int i, int j){
  return (i-1)*N+j;
}

bool Perculation::isFull(int i, int j){
  return isFullUnionFind->connected(0, arrayIndex(i,j));
}

bool Perculation::percolates(){
  return percolatesUnionFind->connected(0, lastIndex);
}

bool Perculation::isOpen(int i, int j){
  return dataSet[(i-1)*N+j-1];
}

void Perculation::open(int i, int j){
  if(isOpen(i, j)){
    return;
  }

  dataSet[(i-1)*N+j-1] = true;

  if(i > 1){
    if(isOpen(i - 1,j)){
      percolatesUnionFind->unify(arrayIndex(i,j), arrayIndex(i-1,j));
      isFullUnionFind->unify(arrayIndex(i,j), arrayIndex(i-1,j));
    }
  } else {
    percolatesUnionFind->unify(0, arrayIndex(i, j));
    isFullUnionFind->unify(0, arrayIndex(i,j));
  }

  if(i < N){
    if(isOpen(i + 1,j)){
      percolatesUnionFind->unify(arrayIndex(i,j), arrayIndex(i+1,j));
      isFullUnionFind->unify(arrayIndex(i,j), arrayIndex(i+1,j));
    }
  } else {
    percolatesUnionFind->unify(lastIndex, arrayIndex(i, j));
  }


  if(j > 1 && isOpen(i,j-1)){
    percolatesUnionFind->unify(arrayIndex(i,j), arrayIndex(i,j-1));
    isFullUnionFind->unify(arrayIndex(i,j), arrayIndex(i,j-1));
  } 

  if(j < N && isOpen(i,j+1)){
    percolatesUnionFind->unify(arrayIndex(i,j), arrayIndex(i,j+1));
    isFullUnionFind->unify(arrayIndex(i,j), arrayIndex(i,j+1));
  } 
}

Perculation* createPerculation(int N){
  Perculation* pr = new Perculation;
  pr->N = N;
  pr->lastIndex = N*N+1;
  pr->isFullUnionFind = createWeightedQuickUnion(pr->lastIndex + 1);
  pr->percolatesUnionFind = createWeightedQuickUnion(pr->lastIndex + 1);
  pr->dataSet = new bool[N*N];
  std::fill(pr->dataSet, pr->dataSet + N*N, 0);
  return pr;
}




class PerculationStats{
  public:
    double mean;
    double stddev;
    int T;
    double* runMonteCarlo(int N);
    double runMonteCarloInstance(int N);
    double calculateMean(double* results);
    double calculateStdDev(double* results);
    double confidenceLo();
    double confidenceHi();
    ~PerculationStats();
};

PerculationStats::~PerculationStats(void){
}

double PerculationStats::runMonteCarloInstance(int N){
  Perculation* pr = createPerculation(N);
  double openSites = 0.0;
  while(!pr->percolates()){
    int i = rand() % (N) + 1;
    int j = rand() % (N) + 1;
    if(!pr->isOpen(i,j)){
      pr->open(i,j);
      openSites+=1;
    }
  }
  delete pr;
  return openSites/(N*N);
}

double* PerculationStats::runMonteCarlo(int N){
  srand(time(NULL));
  double* results = new double[T];

  for (int i = 0; i < T; i++) {
    results[i] = 0;
  }

  for (int i = 0; i < T; i++) {
    results[i] = runMonteCarloInstance(N);
  }
  return results;
}

double PerculationStats::calculateMean(double* results){
  double sum = 0;
  for(int i = 0; i < T; i++)
    sum += results[i];
  return sum / T;
}

double PerculationStats::calculateStdDev(double *results){
  double media = mean, o2 = 0;
  for(int i = 0; i < T; i++)
    o2 += (results[i] - media) * (results[i] - media);
  return sqrt(o2 / (T - 1));
}

double PerculationStats::confidenceLo(){
  return mean - 1.96 * stddev / sqrt( T);
}

double PerculationStats::confidenceHi(){
  return mean + 1.96 * stddev / sqrt(T);
}

PerculationStats* createPerculationStats(int N, int T){
  PerculationStats* ps = new PerculationStats;
  ps->T = T;
  double* results = ps->runMonteCarlo(N);
  ps->mean = ps->calculateMean(results);
  ps->stddev = ps->calculateStdDev(results);
  delete[] results;
  return ps;
}


////////////////////





int main()
{

  /* Perculation* pr = createPerculation(2); */
  /* pr->open(1, 1); */
  /* pr->open(2, 1); */
  /* std::cout << pr->percolates() << std::endl; */
  /* std::cout << uf->getLargest(4) << std::endl; */
  /* std::cout << uf->getLargest(6) << std::endl; */
  PerculationStats* stats = createPerculationStats(2, 10000);
  std::cout << stats->mean << std::endl;
  std::cout << stats->stddev << std::endl;
  std::cout << stats->confidenceLo() << ", " << stats->confidenceHi() <<std::endl;
  delete stats;
  return 0;
}
