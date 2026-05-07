#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<int> adj[], int size) {
    vector<bool> visited(size, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) { 
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int size = 5;
    vector<int> adj[5];
    adj[0] = {1, 2}; 
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    BFS(0, adj, size);

    return 0;
}