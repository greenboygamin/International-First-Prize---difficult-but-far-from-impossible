#include <bits/stdc++.h>
using namespace std;

#define task ""
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

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

struct Rect {
    int a,b,c,d;
    int idx;
};

struct BITmax {
    int n;
    vector<int> bit;
    BITmax(int _n=0){init(_n);}
    void init(int _n){
        n=_n;
        bit.assign(n+1, 0);
    }
    void upd(int i, int val){
        for(; i<=n; i+=i&-i) bit[i] = max(bit[i], val);
    }
    int query(int i){
        int res = 0;
        for(; i>0; i-=i&-i) res = max(res, bit[i]);
        return res;
    }
};

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<Rect> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        a[i].idx = i;
    }
    vector<int> vals;
    vals.reserve(2*k);
    for (int i = 0; i < k; ++i) {
        vals.push_back(a[i].c);
        vals.push_back(a[i].d);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto get_pos = [&](int x)->int{
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    vector<int> order_a(k);
    iota(order_a.begin(), order_a.end(), 0);
    sort(order_a.begin(), order_a.end(), [&](int i, int j){
        if (a[i].a != a[j].a) return a[i].a < a[j].a;
        return a[i].b < a[j].b;
    });

    vector<int> order_b(k);
    iota(order_b.begin(), order_b.end(), 0);
    sort(order_b.begin(), order_b.end(), [&](int i, int j){
        if (a[i].b != a[j].b) return a[i].b < a[j].b;
        return a[i].a < a[j].a;
    });

    vector<int> dp(k, 1);
    BITmax bit((int)vals.size());
    int ptr_b = 0;
    int ans = 0;
    for (int idx = 0; idx < k; ++idx) {
        int i = order_a[idx];
        while (ptr_b < k && a[order_b[ptr_b]].b < a[i].a) {
            int j = order_b[ptr_b];
            int posd = get_pos(a[j].d);
            bit.upd(posd, dp[j]);
            ++ptr_b;
        }
        int posc = int(lower_bound(vals.begin(), vals.end(), a[i].c) - vals.begin()); 
        int best = 0;
        if (posc > 0) best = bit.query(posc);
        dp[i] = best + 1;
        ans = max(ans, dp[i]);
    }

    cout << ans << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
