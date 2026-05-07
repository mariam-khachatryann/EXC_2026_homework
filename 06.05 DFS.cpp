#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}

int main() {
    int n = 5; 
    vector<int> adj[5];
    vector<bool> visited(5, false); 
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    DFS(0, adj, visited);

    return 0;
}