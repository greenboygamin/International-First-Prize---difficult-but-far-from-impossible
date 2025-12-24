#include <bits/stdc++.h>
using namespace std;

#define task "test"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;


ll m, n, s, t, d[N];
vll trace(N, -1);
bool visited[N];
vpll adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void solve() {
    cin >> m >> n >> s >> t;

    // Input the graph
    for (int i = 1; i <= m; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        adj[x].pb({y, val});
        adj[y].pb({x, val});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> kiu;
    fill(d, d + N, INF);
    memset(visited, 0, sizeof visited);

    d[s] = 0; // Distance to the source is zero
    kiu.push({0, s}); // Push the source into the priority queue

    while (!kiu.empty()) {
        ll u = kiu.top().second;
        kiu.pop();

        if (visited[u]) continue; // Skip if already visited
        visited[u] = 1; // Mark u as visited

        for (int idx = 0; idx < adj[u].size(); idx++) {
            ll v = adj[u][idx].first;   // Neighbor
            ll val = adj[u][idx].second; // Weight

            if (d[v] > d[u] + val) {
                d[v] = d[u] + val; // Update distance
                trace[v] = u;      // Update the trace
                kiu.push({d[v], v}); // Push updated distance into the queue
            }
        }
    }

    // Output the cost
    cout << (d[t] == INF ? -1 : d[t]) << el;

    // Reconstruct the path
    if (d[t] != INF) {
        vector<ll> path;
        for (ll v = t; v != -1; v = trace[v]) {
            path.pb(v);
        }
        reverse(path.begin(), path.end()); // Reverse to get the correct order

        // Print the path
        for (auto node : path) {
            cout << node << " ";
        }
        cout << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
