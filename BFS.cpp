/* Breadth First Search (BFS): Application:Indexing web pages for search engines. Example: A web crawler uses BFS to visit web pages systematically, starting from a seed URL and exploring links level by level. Nodes represent web pages. Edges represent hyperlinks. BFS ensures that pages at the same "depth" (distance from the starting page) are visited before moving to deeper levels. Write a program to simulate the indexing of web pages for a search engine using a Breadth-First Search (BFS) algorithm. */
#include <iostream>
#include <queue>
using namespace std;

class Graph {
    int vertices;               // stores number of vertices (web pages)
    int adjMatrix[10][10];      // adjacency matrix for graph
    int visited[10];            // marks visited nodes (indexed web pages)

public:
    // Function to read graph details
    void readGraph() {
        int edges;
        cout << "\nEnter number of vertices: ";
        cin >> vertices;

        // initialize matrix and visited array to 0
        for (int i = 1; i <= vertices; i++) {
            for (int j = 1; j <= vertices; j++) {
                adjMatrix[i][j] = 0;
            }
            visited[i] = 0;
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (u v):\n";
        for (int k = 0; k < edges; k++) {
            int u, v;
            cin >> u >> v;
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // undirected graph
        }
    }

    // Breadth First Search function
    void bfs(int start) {
        queue<int> q;
        visited[start] = 1;
        q.push(start);

        cout << "Page " << start << " indexed\n";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // explore all connected pages
            for (int i = 1; i <= vertices; i++) {
                if (adjMatrix[node][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    cout << "Page " << i << " indexed\n";
                    q.push(i);
                }
            }
        }
    }

    // Function to start BFS traversal
    void performBFS() {
        int start;
        cout << "Enter starting vertex: ";
        cin >> start;
        cout << "\nBFS Traversal (Web Indexing Order):\n";
        bfs(start);
        cout << endl;
    }
};

int main() {
    Graph g;
    cout << "Name: Reva Kulkarni  PRN: B24CE1134\n";
    g.readGraph();
    g.performBFS();
    return 0;
}
