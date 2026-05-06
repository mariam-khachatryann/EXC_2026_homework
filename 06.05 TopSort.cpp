#include <iostream>
#include <vector>
using namespace std;

void allTopSort(vector<vector<int>>& adj,
                vector<int>& in_degree,
                vector<bool>& used,
                vector<int>& cur,
                int V) {

    bool found = false;

    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0 && !used[i]) {

            used[i] = true;
            cur.push_back(i);

            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                in_degree[v]--;
            }

            allTopSort(adj, in_degree, used, cur, V);
            
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                in_degree[v]++;
            }

            used[i] = false;
            cur.pop_back();

            found = true;
        }
    }

    if (!found) {
        for (int i = 0; i < cur.size(); i++) {
            cout << cur[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;

    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);

    vector<int> in_degree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            in_degree[v]++;
        }
    }

    vector<bool> used(V, false);
    vector<int> cur;

    allTopSort(adj, in_degree, used, cur, V);

    return 0;
}