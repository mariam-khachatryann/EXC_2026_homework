#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
int main() { 
    int V = 6; 
    vector<int> adj[6]; 
    adj[0].push_back(1); 
    adj[0].push_back(2); 
    adj[1].push_back(3); 
    adj[2].push_back(3); 
    adj[3].push_back(4); 
    adj[4].push_back(5); 
    vector<int> in_degree(V, 0); 
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < adj[i].size(); j++) { 
            int v = adj[i][j]; in_degree[v]++; 
        } 
    } 
    queue<int> q; 
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    } 
    while (!q.empty()) {
        int u = q.front(); 
        q.pop(); 
        cout << u << " "; 
        
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j]; 
            in_degree[v]--; 
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    } 
    
    return 0; 
}
