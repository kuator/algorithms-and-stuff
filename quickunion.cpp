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

class QuickUnion {
  public:
    int find(int i);
    void Union(int x, int y );
    int getComponents();
    bool isCycle();
    ~QuickUnion();
    int * parents;
    Graph * graph;
};

QuickUnion::~QuickUnion(void){
  delete graph;
  delete[] parents;
}

/* WeightedQuickUnion::WeightedQuickUnion(int V, int E){ */
/*   graph = createGraph(V, E); */
/*   parents = new int[graph -> V]; */
/*   std::fill(parents, parents + graph->V, -1); */
/* } */


int QuickUnion::find(int i){
  if (parents[i] == -1) {
    return i;
  } 

  return find(parents[i]);
}

void QuickUnion::Union(int x, int y ){
  int xset = find(x);
  int yset = find(y);

  if (xset != yset) {
    parents[xset] = yset;
  }
}

bool QuickUnion::isCycle(){
  for (int i = 0; i < graph->E; ++i) {
    int x  = find(graph->edge[i].src);
    int y  = find(graph->edge[i].dest);
    if (x == y) {
      return 1;
    }
    Union(x, y);
  }
  return 0;
}

QuickUnion* createWeightedQuickUnion(int V, int E){
  QuickUnion* uf = new QuickUnion;
  uf->graph = createGraph(V, E);
  uf->parents = new int[uf->graph->V];
  std::fill(uf->parents, uf->parents + uf->graph->V, -1);
  return uf;
}

int main()
{
  QuickUnion* uf = createWeightedQuickUnion(3,3);

  uf->graph->edge[0].src = 0;
  uf->graph->edge[0].dest = 1;
  uf->graph->edge[1].src = 1;
  uf->graph->edge[1].dest = 2;
  uf->graph->edge[2].src = 0;
  uf->graph->edge[2].dest = 2;

  if (uf->isCycle()) {
    std::cout << "cycle detected" << std::endl;
  }
  else {
    std::cout << "no cycle detected" << std::endl;
  }

  delete uf;
  return 0;
}
