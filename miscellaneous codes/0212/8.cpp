    #include <bits/stdc++.h>
    using namespace std;

    #define task ""
    #define el "\n"
    #define pb push_back
    #define fi first
    #define se second
    typedef long long int ll;
    typedef long double ld;
    typedef vector<pair<ll, ll>> vpll;
    typedef vector<int> vi;
    typedef vector<pair<int, int>> vpii;
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
    const ll TMP = 1e5;
    const ll INF = 0x3f3f3f3f3f3f;
    const ll MOD = 2e18;
    const int Z = 12500000;
    const int SZ = 25000005;

    int c[SZ], n, a[N];
    ll s[N];
    vi d;

    void tassk() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        if (fopen(task".inp", "r")) {
            freopen(task".inp", "r", stdin);
            freopen(task".out", "w", stdout);
        }
    }

    ll C2(ll x){
        return x * (x - 1) / 2;
    }

    ll C3(ll x){
        return x * (x - 1) * (x - 2) / 6;
    }

    void solve() {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                int val = s[j] - s[i - 1];
                if (c[val + Z] == 0) d.pb(val);
                c[val + Z]++;
            }
        }
        sort(d.begin(), d.end());
        ll ans = 0;
        int k = d.size();
        for (int i = 0; i < k; i++){
            int v1 = d[i]; if (v1 > 0) break;
            int l = i, r = k - 1;
            while (l <= r){
                int v2 = d[l], v3 = d[r];
                int sum = v1 + v2 + v3;
                if (sum == 0){
                    ll c1 = c[v1 + Z];
                    ll c2 = c[v2 + Z];
                    ll c3 = c[v3 + Z];
                    if (i == l && l == r) ans += C3(c1);
                    else if (i == l && l < r) ans += C2(c1) * c3;
                    else if (i < l && l == r) ans += c1 * C2(c2);
                    else ans += c1 * c2 * c3;
                    l++; r--;
                }
                else if (sum < 0) l++;
                else r--;
            } 
        }
        cout << ans << el;
    }

    int main() {
        tassk();
        solve();
        return 0;
    }

    /*
    █████       █████  █████   █████████  █████   ████ █████ █████
    ▒▒███       ▒▒███  ▒▒███   ███▒▒▒▒▒███▒▒███   ███▒ ▒▒███ ▒▒███ 
    ▒███        ▒███   ▒███  ███     ▒▒▒  ▒███  ███    ▒███  ▒███ 
    ▒███        ▒███   ▒███ ▒███          ▒███████     ▒███  ▒███ 
    ▒███        ▒███   ▒███ ▒███          ▒███▒▒███    ▒███  ▒███ 
    ▒███      █ ▒███   ▒███ ▒▒███     ███ ▒███ ▒▒███   ▒███  ▒███ 
    ███████████ ▒▒████████   ▒▒█████████  █████ ▒▒████ █████ █████
    ▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒ 
    */