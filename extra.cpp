#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to perform DFS and count the minimum number of buses
int dfs(int node, int parent, const vector<vector<int>>& adj, const vector<int>& passengers) {
    int buses = 0;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            buses += dfs(neighbor, node, adj, passengers);
        }
    }
    // If the current node has passengers and is not the root (stop 1), increment buses
    if (passengers[node - 1] == 1 && node != 1) {
        buses += 1;
    }
    return buses;
}

// Function to solve the problem
int solve(int N, vector<int>& passengers, vector<pair<int, int>>& edges) {
    // Build adjacency list for the tree
    vector<vector<int>> adj(N + 1);
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from stop 1
    return dfs(1, -1, adj, passengers);
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N;
        cin >> N; // Number of stops
        vector<int> passengers(N);
        for (int i = 0; i < N; i++) {
            cin >> passengers[i]; // Passengers at each stop
        }
        vector<pair<int, int>> edges(N - 1);
        for (int i = 0; i < N - 1; i++) {
            cin >> edges[i].first >> edges[i].second; // Roads between stops
        }

        // Call the solve function
        int result = solve(N, passengers, edges);
        cout << result << endl;
    }
    return 0;
}