#include <bits/stdc++.h>
using namespace std;

#define task "train"
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
const ll N = 200005;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

int n, q;
ll v[N], t[N];

struct Node {
    ll s, m;
} st[4 * N];

void bd(int k, int l, int r) {
    if (l == r) {
        st[k] = {t[l], v[l]};
        return;
    }
    int mid = (l + r) / 2;
    bd(2 * k, l, mid);
    bd(2 * k + 1, mid + 1, r);
    st[k].s = st[2 * k].s + st[2 * k + 1].s;
    st[k].m = max(st[2 * k].m, st[2 * k + 1].m);
}

void up1(int k, int l, int r, int p, ll val) {
    if (l == r) {
        st[k].m = val;
        v[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) up1(2 * k, l, mid, p, val);
    else up1(2 * k + 1, mid + 1, r, p, val);
    st[k].m = max(st[2 * k].m, st[2 * k + 1].m);
}

void up2(int k, int l, int r, int p, ll val) {
    if (l == r) {
        st[k].s = val;
        t[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) up2(2 * k, l, mid, p, val);
    else up2(2 * k + 1, mid + 1, r, p, val);
    st[k].s = st[2 * k].s + st[2 * k + 1].s;
}

ll get(int k, int l, int r, int u, int v) {
    if (u > v) return 0;
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[k].s;
    int mid = (l + r) / 2;
    return get(2 * k, l, mid, u, v) + get(2 * k + 1, mid + 1, r, u, v);
}

int f1(int k, int l, int r, ll val) {
    if (l == r) return (st[k].s <= val) ? l : l - 1;
    int mid = (l + r) / 2;
    if (st[2 * k].s > val) return f1(2 * k, l, mid, val);
    return f1(2 * k + 1, mid + 1, r, val - st[2 * k].s);
}

int f2(int k, int l, int r, int u, int v, ll x) {
    if (l > v || r < u || st[k].m < x) return -1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    int res = -1;
    if (u <= mid) res = f2(2 * k, l, mid, u, v, x);
    if (res != -1) return res;
    return f2(2 * k + 1, mid + 1, r, u, v, x);
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
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    bd(1, 1, n);
    while (q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i; ll x;
            cin >> i >> x;
            up1(1, 1, n, i, x);
        } else if (k == 2) {
            int i; ll x;
            cin >> i >> x;
            up2(1, 1, n, i, x);
        } else {
            int l; ll b, x;
            cin >> l >> b >> x;
            ll pre = get(1, 1, n, 1, l - 1);
            ll lim = pre + b;
            int rb;
            if (st[1].s <= lim) rb = n;
            else rb = f1(1, 1, n, lim);
            if (rb < l) {
                cout << -1 << el;
                continue;
            }
            cout << f2(1, 1, n, l, rb, x) << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}