#include<iostream>
#include<list>
using namespace std;

class Graph {
  public:
    int num_vertices;
    // Array of list
    list<int> *adjlist;

  Graph(int num_vertices) {
    this->num_vertices = num_vertices;
    this->adjlist = new list<int>[num_vertices];
  }

  void addEdge(int src, int dest) {
    adjlist[src].push_back(dest);
    adjlist[dest].push_back(src);
  }

  void printGraph() {
    for (int i = 0; i < this->num_vertices; i++) {
      cout << "Vertex " << i << ": ";
      for (int x : this->adjlist[i]) {
        cout << x << " ";
      }
      cout << endl;
    }
  }

};

int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.printGraph();
  return 0;
}