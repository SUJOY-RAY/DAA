#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> adj[],int v,bool visited[]){
    visited[v]=true;
    cout<<v<<" ";
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            DFS(adj,u,visited);
        }   
    }   
}



void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For undirected graph; remove this line for a directed graph
}

int main() {
    int vertices = 7 ;
    vector<int> adj[vertices];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 6);
    addEdge(adj, 3, 4);

    bool visited[vertices] = {false}; 

    cout << "DFS starting from vertex 0: ";
    DFS(adj, 0, visited);
    cout << endl;

    return 0;
}

