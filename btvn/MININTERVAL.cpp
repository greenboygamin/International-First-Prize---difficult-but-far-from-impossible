#include <bits/stdc++.h>
using namespace std;

#define task "MININTERVAL"
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
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

ll n, k;
ll a[N], ans = 0;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

struct SegmentTree{
    vector<pll> st; int size;

    void init(int n){
        st.resize(4 * n + 5, {INF, -1});
        size = n;
    }

    void build(int id, int l, int r){
        if (l == r){
            st[id] = {a[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }

    pll get(int id, int l, int r, int u, int v){
        if (u > r || v < l) return {INF, -1};
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
} Tree;

struct MergeSortTree {
    vector<vector<ll>> seg;
    int N;

    void init(int n) {
        N = n;
        seg.assign(4 * n + 5, vector<ll>());
    }

    void build(int id, int l, int r) {
        if (l == r) {
            seg[id].clear();
            seg[id].push_back(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id].resize(seg[id<<1].size() + seg[id<<1|1].size());
        std::merge(seg[id<<1].begin(), seg[id<<1].end(),
                   seg[id<<1|1].begin(), seg[id<<1|1].end(),
                   seg[id].begin());
    }

    int countLE(int id, int l, int r, int u, int v, ll val) {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) {
            return (int)(upper_bound(seg[id].begin(), seg[id].end(), val) - seg[id].begin());
        }
        int mid = (l + r) >> 1;
        return countLE(id<<1, l, mid, u, v, val) + countLE(id<<1|1, mid+1, r, u, v, val);
    }
} MST;

void dac(int l, int r){
    if (l > r) return;
    pll mn = Tree.get(1, 1, n, l, r);
    int m = (int)mn.second;
    ll am = a[m];

    dac(l, m - 1);
    dac(m + 1, r);

    int sz_l = m - l + 1;
    int sz_r = r - m + 1;

    if (sz_l <= sz_r) {
        for (int i = l; i <= m; ++i) {
            ll need = k - am - a[i];
            int cnt = 0;
            if (m <= r) cnt = MST.countLE(1, 1, n, m, r, need);
            ans += cnt;
        }
    } else {
        for (int j = m; j <= r; ++j) {
            ll need = k - am - a[j];
            int cnt = 0;
            if (l <= m) cnt = MST.countLE(1, 1, n, l, m, need);
            ans += cnt;
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Tree.init(n); Tree.build(1, 1, n);
    MST.init(n); MST.build(1, 1, n);
    dac(1, n);
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
