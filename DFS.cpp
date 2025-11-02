/* Depth First Search (DFS): Application: Web crawlers use DFS to explore web pages systematically, following links and indexing content for search engines. Write a simple program to index web pages using Depth First Search (DFS). The program should simulate a web graph where pages are represented as nodes and hyperlinks as edges.*/ 
#include <iostream>
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
            // put 1 in matrix to show there is an edge (hyperlink)
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // undirected graph
        }
    }

    // Function for Depth First Search
    void dfs(int node) {
        cout << "Page " << node << " indexed\n"; // simulate indexing
        visited[node] = 1;

        // visit all connected (linked) pages
        for (int i = 1; i <= vertices; i++) {
            if (adjMatrix[node][i] == 1 && visited[i] == 0) {
                dfs(i);
            }
        }
    }

    // Function to start DFS traversal
    void performDFS() {
        int start;
        cout << "Enter starting vertex: ";
        cin >> start;
        cout << "\nDFS Traversal (Web Indexing Order):\n";
        dfs(start);
        cout << endl;
    }
};

int main() {
    Graph g;
    cout << "Name: Reva Kulkarni  PRN: B24CE1134\n";
    g.readGraph();
    g.performDFS();
    return 0;
}
