#include <bits/stdc++.h>
using namespace std;

#define el "\n"
typedef long long ll;

// Input variables
int n, m, q;
vector<vector<int>> graph;
vector<int> color;

// Function to process queries in reverse order using BFS
void process_queries(vector<tuple<int, int, int>> &queries) {
    vector<int> last_colored(n + 1, -1); // Track the last query that colors each vertex
    
    // Process each query in reverse order
    for (int i = q - 1; i >= 0; --i) {
        int u, d, c;
        tie(u, d, c) = queries[i];
        
        queue<pair<int, int>> bfs; // Pair stores (node, current distance)
        bfs.push({u, 0});
        
        while (!bfs.empty()) {
            auto [node, dist] = bfs.front();
            bfs.pop();
            
            // Skip if already colored by a more recent query or distance exceeds the limit
            if (last_colored[node] != -1 || dist > d) continue;
            
            // Mark the node with the query index
            last_colored[node] = i;
            color[node] = c;
            
            // Push neighbors to the queue
            for (int neighbor : graph[node]) {
                if (last_colored[neighbor] == -1) {
                    bfs.push({neighbor, dist + 1});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n + 1);
    color.assign(n + 1, 0);

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // Read queries
    cin >> q;
    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int u, d, c;
        cin >> u >> d >> c;
        queries[i] = {u, d, c};
    }

    // Process queries
    process_queries(queries);

    // Output final colors
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << el;
    }

    return 0;
}
