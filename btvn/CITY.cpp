#include <bits/stdc++.h>
using namespace std;

#define task "CITY"
#define ll long long int
#define pll pair<ll, ll>

const ll INF = 1e9 + 7;
const int M = 1003;
ll n, m;
ll dist[M][M];
vector<pair<int, pll>> edges;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
        edges.push_back({w, {u, v}});
    }
    floyd();
    
    vector<pair<int, int>> ans;
    ll sum = 0;
    
    for (auto uv : edges) {
        int u = uv.second.first, v = uv.second.second;
        
        bool prune = false;
        for (int k = 1; k <= n; k++) {
            if (k != u && k != v && dist[u][k] + dist[k][v] <= uv.first) {
                prune = true;
                break;
            }
        }
        
        if (!prune) {
            ans.push_back({u, v});
            sum += uv.first;
        }
    }
    
    cout << ans.size() << " " << sum << "\n";
    for (auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
