// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std; 

class Edge {
  public:
    int src, dest;
    string date, time;
};

class Graph {
  public:
    int V, E;
    Edge* edge;
    ~Graph();  
};

class Subset 
{ 
  public:
    int parent; 
    int rank; 
}; 

Graph::~Graph(void) {
   delete[] edge;
}

Graph* createGraph(int V, int E){
  Graph* graph = new Graph();
  graph->E = E;
  graph->V = V;
  graph->edge = new Edge[graph->E];

  return graph;
}

class WeightedQuickUnion {
  public:
    int find(int i);
    void Union(int x, int y );
    void UnionEdges();
    int components;
    bool isCycle();
    ~WeightedQuickUnion();
    Subset * subsets;
    Graph * graph;
};

WeightedQuickUnion::~WeightedQuickUnion(void){
  delete graph;
  delete[] subsets;
}


int WeightedQuickUnion::find(int i){
  if (subsets[i].parent != i) {
    subsets[i].parent = find(subsets[i].parent);
  } 

  return subsets[i].parent;
}

void WeightedQuickUnion::Union(int x, int y ){
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

void WeightedQuickUnion::UnionEdges(){
  for (int i = 0; i < graph->E; ++i) {
    int x  = find(graph->edge[i].src);
    int y  = find(graph->edge[i].dest);
    if (x == y) {
      continue;
    }
    Union(x, y);
    if(components == 1){
      std::cout << graph->edge[i].date << " " << graph->edge[i].time <<std::endl;
      return;
    }
  }
}

bool WeightedQuickUnion::isCycle(){
  for (int i = 0; i < graph->E; ++i) {
    int x  = find(graph->edge[i].src);
    int y  = find(graph->edge[i].dest);
    if (x == y) {
      std::cout << graph->edge[i].src << graph->edge[i].dest << std::endl;
      return 1;
    }
    Union(x, y);
  }
  return 0;
}

WeightedQuickUnion* createWeightedQuickUnion(Graph* graph){
  WeightedQuickUnion* uf = new WeightedQuickUnion;
  uf->graph = graph;
  uf->subsets = new Subset[uf->graph->V];
  uf->components = uf->graph->V;
  for (int v = 0; v < uf->graph->V; ++v) { 
       uf->subsets[v].parent = v; 
       uf->subsets[v].rank = 1; 
  } 
  uf->UnionEdges();
  return uf;
}


void resetFileStream(std::ifstream& file){
  file.clear();
  file.seekg(0);
}

int number_of_lines(std::ifstream& file)
{
  resetFileStream(file);
  int count = 0;
  string line;
  while (getline(file, line))
    count++;
  resetFileStream(file);
  return count;
}

int main() {
    int x, y;
    string date, time;
    ifstream inFile;
    inFile.open("timestamps.log");
    int edges = number_of_lines(inFile);
    int friends = 6;
    Graph* graph = createGraph(friends,edges);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    for (int i = 0; inFile >> x >> y >> date >> time; i++) {
      graph->edge[i].src = x;
      graph->edge[i].dest = y;
      graph->edge[i].date = date;
      graph->edge[i].time = time;
    }

    WeightedQuickUnion* uf = createWeightedQuickUnion(graph);
    std::cout << uf->components << std::endl;
    inFile.close();
    delete uf;
    return 0;
}
