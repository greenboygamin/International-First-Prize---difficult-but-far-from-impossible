#include <bits/stdc++.h>
using namespace std;

#define task "MININTERVAL"
#define el ""
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

const ll N = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int n, q;
vector<pll> edges;
vector<int> g[N];

void inp(void) {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edges.pb({u, v});
    }
}
 
int h[N], sz[N], p[N];
 
void dfs(int u, int par) {
    p[u] = par;
    sz[u] = 1;
    for (int v: g[u]) 
        if (v != par) {
            h[v] = h[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
}
 
int head[N], pos[N], inv[N]; 
int timer = 0;
 
void hld(int u, int chain) {
    head[u] = chain;
    pos[u] = ++timer;
    inv[pos[u]] = u; 
 
    int heavy = 0;
    for (int v: g[u]) if (v != p[u] && sz[v] > sz[heavy]) heavy = v;
    
    if (heavy) hld(heavy, chain);
    
    for (int v: g[u])
        if (v != p[u] && v != heavy) hld(v, v);
}
 
int st[10 * N], lazy[10 * N];
 
void fix(int id) {
    if (lazy[id] == 0) return;
    lazy[id << 1] += lazy[id];
    st[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    st[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, ll val) {
    if (l > v || r < u) return;
    fix(id);
    if (l >= u && r <= v) {
        lazy[id] += val;
        st[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    fix(id);
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}
 
void query(int u, int v) {
    for (; head[u] != head[v]; u = p[head[u]]) {
        if (h[head[u]] < h[head[v]]) swap(u, v);
        update(1, 1, n, pos[head[u]], pos[u], 1);
    }
    if (h[u] > h[v]) swap(u, v);
    update(1, 1, n, pos[u], pos[v], 1);
    update(1, 1, n, pos[u], pos[u], -1);
}
 
void process(void) {
    dfs(1, 0);
    hld(1, 1);
    while (q--) {
        int op, u;
        cin >> op >> u;
        if (op == 1) {
            int v; cin >> v;
            query(u, v);
        }
        else {
            int v = edges[u - 1].second;
            u = edges[u - 1].first;
            if (p[u] == v) swap(u, v);
            cout << get(1, 1, n, pos[v], pos[v]) << '\n';
        }
    }
}

int main(){
    tassk();
    inp();
    process();
    return 0;
}
