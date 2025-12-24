#include <bits/stdc++.h>
using namespace std;

#define task "CPTREES"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 3e5 + 7;
const ll M = 2e3 + 7;
const ll B = 505;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

int n;
vi adj1[N], adj2[N];
int tin1[N], tout1[N], timer = 0, r1, r2;
ll ans = 0;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs1(int u, vi adj[], int tin[], int tout[]){
    tin[u] = ++timer;
    for (int v : adj[u]){
        dfs1(v, adj, tin, tout);
    }
    tout[u] = timer; 
}

struct SegmentTree{
    vector<ll> st, lazy;
    int n;

    void init(int _n){
        n = _n;
        st.resize(4 * n + 5, 0);
        lazy.resize(4 * n + 5, 0);
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        st[v] += lazy[v]; 
        if (tl != tr) {
            lazy[v*2] += lazy[v];
            lazy[v*2+1] += lazy[v];
        }
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] += add;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }

    ll query(int v, int tl, int tr, int pos) {
        push(v, tl, tr);
        if (tl == tr) {
            return st[v];
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return query(v*2, tl, tm, pos);
        } else {
            return query(v*2+1, tm+1, tr, pos);
        }
    }
};

SegmentTree seg;

void dfs_solve(int u) {
    ll coms = seg.query(1, 1, n, tin1[u]);
    ans += coms;
    seg.update(1, 1, n, tin1[u], tout1[u], 1);
    for (int v : adj2[u]) {
        dfs_solve(v);
    }
    seg.update(1, 1, n, tin1[u], tout1[u], -1);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        int p; cin >> p;
        if (p == 0) r1 = i;
        else adj1[p].pb(i);
    }
    for (int i = 1; i <= n; i++){
        int p; cin >> p;
        if (p == 0) r2 = i;
        else adj2[p].pb(i);
    }
    
    timer = 0;
    dfs1(r1, adj1, tin1, tout1);
    seg.init(n);
    dfs_solve(r2);
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}