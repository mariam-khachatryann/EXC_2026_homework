#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void primMST(int n, vector<pair<int, int>> adj[]) {
    vector<int> key(n, INF);
    vector<bool> inMST(n, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startNode = 0;
    pq.push({0, startNode});
    key[startNode] = 0;

    int mst_weight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mst_weight += weight;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Total weight of MST: " << mst_weight << endl;
}
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int main() {
    int n = 5;
    vector<pair<int, int>> adj[5];

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    primMST(n, adj);
    return 0;
}