#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;
const ll K = 18;

int n, q;
vector<int> adj[N];
int p[N][K], d[N], st[N][K], lg[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void pre_lg() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
}

void dfs(int u, int par) {
    d[u] = d[par] + 1;
    p[u][0] = par;
    for (int v : adj[u]) {
        if (v != par) dfs(v, u);
    }
}

void pre_lca() {
    for (int j = 1; j < K; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int j = K - 1; j >= 0; j--)
        if (d[u] - (1 << j) >= d[v]) u = p[u][j];
    if (u == v) return u;
    for (int j = K - 1; j >= 0; j--)
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    return p[u][0];
}

void pre_st() {
    for (int i = 1; i <= n; i++) st[i][0] = i;
    for (int j = 1; j < K; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = lca(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    pre_lg();
    dfs(1, 1);
    pre_lca();
    pre_st();
    while (q--){
        int u, v; cin >> u >> v;
        int k = lg[v - u + 1];
        cout << lca(st[u][k], st[v - (1 << k) + 1][k]) << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}

/*
.█████       █████  █████   █████████  █████   ████ █████ █████
▒▒███       ▒▒███  ▒▒███   ███▒▒▒▒▒███▒▒███   ███▒ ▒▒███ ▒▒███ 
.▒███        ▒███   ▒███  ███     ▒▒▒  ▒███  ███    ▒███  ▒███ 
.▒███        ▒███   ▒███ ▒███          ▒███████     ▒███  ▒███ 
.▒███        ▒███   ▒███ ▒███          ▒███▒▒███    ▒███  ▒███ 
.▒███      █ ▒███   ▒███ ▒▒███     ███ ▒███ ▒▒███   ▒███  ▒███ 
.███████████ ▒▒████████   ▒▒█████████  █████ ▒▒████ █████ █████
▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒ 
*/