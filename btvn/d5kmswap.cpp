#include <bits/stdc++.h>
using namespace std;
#define task "d5kmswap"
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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

ll n, k;
ll a[N], bit[N];
pii st[4 * N];

void upd_bit(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

ll get_bit(int idx) {
    ll res = 0;
    for (; idx > 0; idx -= idx & -idx) res += bit[idx];
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {a[l], -l};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void upd_st(int id, int l, int r, int pos) {
    if (l == r) {
        st[id] = {-1, -1};
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) upd_st(id * 2, l, mid, pos);
    else upd_st(id * 2 + 1, mid + 1, r, pos);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

pii get_max(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return {-1, -1};
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get_max(id * 2, l, mid, u, v), get_max(id * 2 + 1, mid + 1, r, u, v));
}

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    vll res;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n, R = 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll cost = (mid - 1) - get_bit(mid - 1);
            if (cost <= k) {
                R = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        pii best = get_max(1, 1, n, 1, R);
        ll val = best.first;
        ll idx = -best.second;

        res.pb(val);
        ll real_cost = (idx - 1) - get_bit(idx - 1);
        k -= real_cost;

        upd_bit(idx, 1);
        upd_st(1, 1, n, idx);
    }

    for (int i = 0; i < n; i++) cout << res[i] << (i == n - 1 ? "" : " ");
}

int main() {
    tassk();
    solve();
    return 0;
}