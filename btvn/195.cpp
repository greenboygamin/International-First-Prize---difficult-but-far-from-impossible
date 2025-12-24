#include <bits/stdc++.h>
using namespace std;

#define task "DOCHOI"
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

const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 4e18;

int n, q, up[20][N], d[N];
vector<int> adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs(int u, int p){
    up[0][u] = p;
    for (int i = 1; i < 20; i++){
        up[u][i] = up[i - 1][up[i - 1][u]];
    }
    for (int v : adj[u]){
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if (d[u] < d[v]) swap(u, v);
    for (int i = 19; i >= 0; i--){
        if (d[u] - (1 << i) >= d[v]) u = up[i][u];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--){
        if (up[i][u] != up[i][v]){
            u = up[i][u]; v = up[i][v];
        }
    }
    return up[0][u];
}

int find_k(int u, int k){
    for (int j = 0; (1 << j) <= k; ++j){
        if ((k >> j) & 1) u = up[j][u];
    }
    return u;
}

int query(int u, int v, int w){
    int uv = lca(u, v);
    int luc = abs(d[u] - d[uv]), ki = abs(d[v] - d[uv]);
    if (w == luc) return uv;
    else if (w < luc){
        return find_k(u, luc - w);
    }
    else {
        return find_k(v, ki - (w - luc));
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, -1);
    while (q--){
        int u, v, w; cin >> u >> v >> w;
        cout << query(u, v, w) << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

#define task "191"
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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

int n, q;
vector<pll> adj[N];
ll up[20][N], depth[N], dist[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void dfs(int u, int p){
    up[0][u] = p;
    for (int i = 1; i < 20; i++){
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (auto [v, val] : adj[u]){
        if (v != p){
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + val;
            dfs(v, u);
        }
    }
}

int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; --i){
        if (depth[u] - (1 << i) >= depth[v]){
            u = up[i][u];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i){
        if (up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    depth[1] = 0;
    dfs(1, 1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        int uv = lca(u, v);
        cout << dist[u] + dist[v] - 2 * dist[uv] << el; 
        //cout << dist[u] << " " << dist[v] << " " << uv << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}*/