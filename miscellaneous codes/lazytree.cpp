#include <bits/stdc++.h>
using namespace std;

#define task ""
#define ll long long int
#define ld long double
#define el "\n"
#define MOD 998244353

const int N = 1e5 + 5;
ll st[4 * N], lazy[4 * N], a[N];
int n, q;
ll x, y, z;
char type;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void build(ll id, ll l, ll r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;   
}

void propagate(ll id, ll l, ll r){
    if (lazy[id] != 0){
        st[id] = (st[id] + (r - l + 1) * lazy[id]) % MOD;
        if (l != r){
            lazy[id * 2] = (lazy[id * 2] + lazy[id]) % MOD;
            lazy[id * 2 + 1] = (lazy[id * 2 + 1] + lazy[id]) % MOD;
        }
        lazy[id] = 0;
    }
}

void update(ll id, ll l, ll r, ll u, ll v, ll val){
    propagate(id, l, r);
    if (r < u || v < l){
        return;
    }
    if (u <= l && r <= v){
        lazy[id] = (lazy[id] + val) % MOD;
        propagate(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
}

ll get(ll id, ll l, ll r, ll u, ll v){
    propagate(id, l, r);
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    ll mid = (l + r) >> 1;
    ll left = get(id * 2, l, mid, u, v);
    ll right = get(id * 2 + 1, mid + 1, r, u, v);
    return (left + right) % MOD;
    
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--){
        cin >> type >> x >> y;
        if (type == 'I'){
            cin >> z;
            update(1, 1, n, x, y, z);
        }
        else {
            cout << get(1, 1, n, x, y) << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
