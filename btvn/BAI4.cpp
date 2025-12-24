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
        int uv = lca(u, v);
        int dist = d[u] + d[v] - 2 * d[uv]; 
    }
}

int main() {
    tassk();
    solve();
    return 0;
}