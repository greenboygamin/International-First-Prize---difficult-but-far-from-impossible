    #include <bits/stdc++.h>
    using namespace std;

    #define task "HAMMING"
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
    const ll N = 1e5 + 5;
    const ll M = 1e3 + 5;
    const ll TMP = 1e5;
    const ll INF = 0x3f3f3f3f3f3f;
    const ll MOD = 1e9 + 7;

    ll n, l, r, a[N], c[N];

    void tassk() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        if (fopen(task".inp", "r")) {
            freopen(task".inp", "r", stdin);
            freopen(task".out", "w", stdout);
        }
    }

    ll bienl(ll lnow, ll rnow, ll val){
        ll res = -1;
        while (lnow <= rnow){
            ll mid = (lnow + rnow) >> 1;
            if (val - c[mid - 1] >= l){
                lnow = mid + 1;
                res = mid;
            }
            else rnow = mid - 1;
        }
        return res;
    }

    ll bienr(ll lnow, ll rnow, ll val){
        ll res = -1;
        while (lnow <= rnow){
            ll mid = (lnow + rnow) >> 1;
            if (val - c[mid - 1] <= r){
                rnow = mid - 1;
                res = mid;
            }
            else lnow = mid + 1;
        }
        return res;
    }

    void solve() {
        cin >> n >> l >> r;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll dem = 0;
        vll c;
        c.pb(0);
        ll sums = 0;
        for (int right = 1; right <= n; right++){
            sums += a[right];
            dem += distance(lower_bound(c.begin(), c.end(), sums - r), upper_bound(c.begin(), c.end(), sums - l));
            c.insert(upper_bound(c.begin(), c.end(), sums), sums);
        }
        cout << dem;
    }

    int main() {
        tassk();
        solve();
        return 0;
    }
