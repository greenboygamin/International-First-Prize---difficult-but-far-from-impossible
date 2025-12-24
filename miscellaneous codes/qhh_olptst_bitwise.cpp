#include <bits/stdc++.h>
using namespace std;

#define task "bitwise"
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
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;
const int K = 20; 

struct TVal {
    int v0, v1;
};

struct Node {
    TVal val, inv;
};

int n, q;
int t[N], x[N];
Node st[K][4 * N];
bool lazy[K][4 * N];
TVal op_on[N][K];
TVal id_val = {0, 1};

TVal merge(TVal l, TVal r){
    TVal res;
    res.v0 = (l.v0 == 0) ? r.v0 : r.v1;
    res.v1 = (l.v1 == 0) ? r.v0 : r.v1;
    return res;
}

void precalc() {
    for (int i = 1; i <= n; ++i){
        for (int k = 0; k < K; ++k){
            int xk = (x[i] >> k) & 1;
            if (t[i] == 1){
                op_on[i][k] = (xk == 0) ? TVal{0, 0} : TVal{0, 1};
            } else if (t[i] == 2){
                op_on[i][k] = (xk == 1) ? TVal{1, 1} : TVal{0, 1};
            } else {
                op_on[i][k] = (xk == 1) ? TVal{1, 0} : TVal{0, 1}; 
            }
        }
    }
}

void apply(int k, int v){
    swap(st[k][v].val, st[k][v].inv);
    lazy[k][v] = !lazy[k][v];
}

void push(int k, int v){
    if (lazy[k][v]){
        apply(k, v * 2);
        apply(k, v * 2 + 1);
        lazy[k][v] = false;
    }
}

void build(int k, int v, int tl, int tr){
    lazy[k][v] = false;
    if (tl == tr){
        st[k][v].val = op_on[tl][k];
        st[k][v].inv = id_val;
    } else {
        int tm = (tl + tr) / 2;
        build(k, v * 2, tl, tm);
        build(k, v * 2 + 1, tm + 1, tr);
        st[k][v].val = merge(st[k][v * 2].val, st[k][v * 2 + 1].val);
        st[k][v].inv = merge(st[k][v * 2].inv, st[k][v * 2 + 1].inv);
    }
}

void upd(int k, int v, int tl, int tr, int l, int r) {
    if (l > r) return;
    push(k, v);
    if (l == tl && r == tr) {
        apply(k, v);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(k, v * 2, tl, tm, l, min(r, tm));
    upd(k, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    st[k][v].val = merge(st[k][v * 2].val, st[k][v * 2 + 1].val);
    st[k][v].inv = merge(st[k][v * 2].inv, st[k][v * 2 + 1].inv);
}

TVal qry(int k, int v, int tl, int tr, int l, int r) {
    if (l > r) return id_val;
    push(k, v);
    if (l == tl && r == tr) {
        return st[k][v].val;
    }
    int tm = (tl + tr) / 2;
    TVal ql = qry(k, v * 2, tl, tm, l, min(r, tm));
    TVal qr = qry(k, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return merge(ql, qr);
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> x[i];
    }
    
    precalc();
    for (int k = 0; k < K; ++k) {
        build(k, 1, 1, n);
    }

    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            for (int k = 0; k < K; ++k) {
                upd(k, 1, 1, n, l, r);
            }
        } else {
            int pos, s;
            cin >> pos >> s;
            int ans = 0;
            for (int k = 0; k < K; ++k) {
                TVal res_k = qry(k, 1, 1, n, 1, pos);
                int b_in = (s >> k) & 1;
                int b_out = (b_in == 0) ? res_k.v0 : res_k.v1;
                if (b_out == 1) {
                    ans |= (1 << k);
                }
            }
            cout << ans << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}