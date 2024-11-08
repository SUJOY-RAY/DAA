#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++) cout << i << " : " << dist[i] << "\n";
}



void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); // For undirected graph; remove this line for directed graph
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> adj[V];

    // Add edges: addEdge(adj, u, v, weight)
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 10);
    addEdge(adj, 1, 3, 50);
    addEdge(adj, 2, 3, 20);
    addEdge(adj, 3, 4, 60);

    int src = 0; // Starting source vertex
    cout << "Shortest distances from vertex " << src << ":\n";
    dijkstra(adj, V, src);

    return 0;
}
