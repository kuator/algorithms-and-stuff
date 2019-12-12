#include <bits/stdc++.h>
using namespace std; 

class Edge {
  public:
    int src, dest;
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

int main()
{

  Graph* graph = createGraph(9,9);
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[2].src = 1;
  graph->edge[2].dest = 3;
  graph->edge[3].src = 3;
  graph->edge[3].dest = 4;
  graph->edge[4].src = 2;
  graph->edge[4].dest = 4;
  graph->edge[5].src = 4;
  graph->edge[5].dest = 5;
  graph->edge[6].src = 5;
  graph->edge[6].dest = 6;
  graph->edge[7].src = 6;
  graph->edge[7].dest = 7;
  graph->edge[8].src = 7;
  graph->edge[8].dest = 8;

  WeightedQuickUnion* uf = createWeightedQuickUnion(graph);

  if (uf->isCycle()) {
    std::cout << "cycle detected" << std::endl;
  }
  else {
    std::cout << "no cycle detected" << std::endl;
  }

  delete uf;
  return 0;
}
