#include <bits/stdc++.h>
using namespace std;
#define task "KNAPSACK"
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

const ll N = 1e4 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

struct Item { int w, v; };
struct Query { int l, r, w, id; };

int n, q;
Item a[N];
int res[100005];
int f[N][105];

void calc(int l, int r, vector<Query>& qs) {
    if (qs.empty()) return;
    if (l == r) {
        for (auto& x : qs) 
            res[x.id] = (a[l].w <= x.w ? a[l].v : 0);
        return;
    }
    
    int mid = (l + r) >> 1;
    vector<Query> ql, qr, qc;
    for (auto& x : qs) {
        if (x.r <= mid) ql.pb(x);
        else if (x.l > mid) qr.pb(x);
        else qc.pb(x);
    }

    if (!qc.empty()) {
        for (int j = 0; j <= 100; ++j) 
            f[mid][j] = (j >= a[mid].w ? a[mid].v : 0);
        for (int i = mid - 1; i >= l; --i) {
            for (int j = 0; j <= 100; ++j) {
                f[i][j] = f[i + 1][j];
                if (j >= a[i].w) f[i][j] = max(f[i][j], f[i + 1][j - a[i].w] + a[i].v);
            }
        }

        for (int j = 0; j <= 100; ++j) 
            f[mid + 1][j] = (j >= a[mid + 1].w ? a[mid + 1].v : 0);
        for (int i = mid + 2; i <= r; ++i) {
            for (int j = 0; j <= 100; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= a[i].w) f[i][j] = max(f[i][j], f[i - 1][j - a[i].w] + a[i].v);
            }
        }

        for (auto& x : qc) {
            int mx = 0;
            for (int k = 0; k <= x.w; ++k) 
                mx = max(mx, f[x.l][k] + f[x.r][x.w - k]);
            res[x.id] = mx;
        }
    }

    calc(l, mid, ql);
    calc(mid + 1, r, qr);
}

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].v;
    cin >> q;
    vector<Query> qs;
    for (int i = 0; i < q; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        qs.pb({l, r, w, i});
    }
    calc(1, n, qs);
    for (int i = 0; i < q; ++i) cout << res[i] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}