#include<iostream>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph {
  public:
    int num_vertices;
    // Array of list
    list<int> *adjlist;
    bool *visited;

  Graph(int num_vertices) {
    this->num_vertices = num_vertices;
    this->adjlist = new list<int>[num_vertices];
    this->visited = new bool[num_vertices];
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

void bfs(Graph *g, int starting_vertex) {
  bool visited[g->num_vertices];
  queue<int> q;

  q.push(starting_vertex); // push first vertex into q
  visited[starting_vertex] = true; // record first vertex as being visited

  while (!q.empty()) {
    int visited_vertex = q.front();
    q.pop(); // remove first item from q

    for (int vertex : g->adjlist[visited_vertex]) {
      if (!visited[vertex]) {
        q.push(vertex); // push vertex into q
        visited[vertex] = true; // mark vertex as visited
        cout << vertex << " ";
      }
    }
  }
}

void dfs(Graph *g, int starting_vertex, bool visited[]) {
  visited[starting_vertex] = true;
  for (int vertex : g->adjlist[starting_vertex]) {
    if (!visited[vertex]) {
      visited[vertex] = true;
      cout << vertex << " ";
      dfs(g, vertex, visited);
    }
  }
}

int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  dfs(&g, 2, g.visited);
  return 0;
}