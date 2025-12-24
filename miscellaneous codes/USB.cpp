#include <bits/stdc++.h>
using namespace std;

#define task "USB"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 5e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 1e6;

ll n, x;
struct price{
    ll val, id;
} c[N];
vll b;

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

struct Fenwick
{
    int size;
    vector<int> bit;
    void init(int n)
    {
        size = n;
        bit.assign(n + 1, 0);
    }
    void update(int id, int val)
    {
        for (; id <= size; id += id & -id)
            bit[id] = max(bit[id], val);
    }
    int get_max(int id)
    {
        int res = 0;
        for (; id >= 1; id -= id & -id)
            res = max(res, bit[id]);
        return res;
    }
} dp, dp2;

void compress(){
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++) c[i].id = lower_bound(b.begin(), b.end(), c[i].val) - b.begin() + 1;
}

void Solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        cin >> c[i].val;
        b.pb(c[i].val);
        b.pb(c[i].val + x);
    }
    compress();
    int m = b.size();
    dp.init(m); dp2.init(m);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int pos = c[i].id;
        ll val1 = dp.get_max(pos - 1) + 1;
        int pos2 = lower_bound(b.begin(), b.end(), c[i].val + x) - b.begin() + 1;
        ll val2 = max(dp2.get_max(pos - 1) + 1, dp.get_max(pos2 - 1) + 1);
        dp.update(pos, val1);
        dp2.update(pos, val2);
        ans = max({ans, val1, val2}); 
    }
    cout << ans;
}

int main() {
    Task();
    Solve();
    return 0;
}


