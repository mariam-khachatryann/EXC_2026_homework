#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; 

void dijkstra(int start, vector<pair<int, int>> adj[], int n) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first; 
        int u = pq.top().second; 
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from " << start << " to " << i << " is: " << dist[i] << endl;
    }
}

int main() {
    int n = 5;
    vector<pair<int, int>> adj[5];

    adj[0].push_back({1, 10});
    adj[0].push_back({4, 3});
    adj[4].push_back({1, 1});
    adj[4].push_back({2, 8});
    adj[1].push_back({2, 2});
    adj[2].push_back({3, 9});

    dijkstra(0, adj, n);

    return 0;
}