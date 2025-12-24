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
const ll MOD = 998244353;

int k, m;
ll dp[N];
int a[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll tru(ll a, ll b){
    return (a + MOD - b) % MOD;
}

void solve() {
    cin >> k >> m;
    int mx = 0;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    dp[0] = 1;
    if (k == 1){
        for (int i = 1; i <= m; i++){
            if (a[i] != 1) {
                cout << 0 << el;
                return;
            }
        }
        cout << 1 << el;
        return;
    }
    int n = mx - k;
    ll sums = 1;
    for (int i = 1; i <= n; i++){
        dp[i] = sums;
        sums = add(sums, dp[i]);
        if (i >= k - 1){
            sums = tru(sums, dp[i - k + 1]);
        }
    }
    ll res = 1;
    for (int i = 1; i <= m; i++){
        res = mul(res, dp[a[i] - k]);
    }
    cout << res;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 