#include <bits/stdc++.h>
using namespace std;

#define el "\n"
typedef long long int ll;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll st[4 * N], lazyMul[4 * N], lazyAdd[4 * N], c[N];
int n, q;

void build(ll id, ll l, ll r) {
    if (l == r) {
        st[id] = c[l] % MOD;
        return;
    }
    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
}

void propagate(ll id, ll l, ll r) {
    if (lazyMul[id] != 1 || lazyAdd[id] != 0) {
        st[id] = (st[id] * lazyMul[id] % MOD + (r - l + 1) * lazyAdd[id] % MOD) % MOD;
        
        if (l != r) {
            ll left = id * 2, right = id * 2 + 1;
            lazyMul[left] = (lazyMul[left] * lazyMul[id]) % MOD;
            lazyMul[right] = (lazyMul[right] * lazyMul[id]) % MOD;
            lazyAdd[left] = (lazyAdd[left] * lazyMul[id] + lazyAdd[id]) % MOD;
            lazyAdd[right] = (lazyAdd[right] * lazyMul[id] + lazyAdd[id]) % MOD;
        }
        
        lazyMul[id] = 1;
        lazyAdd[id] = 0;
    }
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    propagate(id, l, r);
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    ll mid = (l + r) >> 1;
    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) % MOD;
}

void update(ll id, ll l, ll r, ll u, ll v, ll a, ll b) {
    propagate(id, l, r);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lazyMul[id] = (lazyMul[id] * a) % MOD;
        lazyAdd[id] = (lazyAdd[id] * a + b) % MOD;
        propagate(id, l, r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, a, b);
    update(id * 2 + 1, mid + 1, r, u, v, a, b);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i < 4 * N; ++i) {
        lazyMul[i] = 1;
        lazyAdd[i] = 0;
    }
    build(1, 1, n);
    while (q--) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        if (type == "MUL") {
            ll a, b;
            cin >> a >> b;
            update(1, 1, n, x, y, a, b);
        } else if (type == "SUM") {
            cout << get(1, 1, n, x, y) << el;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
