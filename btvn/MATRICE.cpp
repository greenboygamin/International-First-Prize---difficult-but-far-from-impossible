#include <bits/stdc++.h>
using namespace std;
#define task "MATRICE"
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
const ll N = 2e5 + 5; 
const ll MOD = 1e9 + 9; 
int n, m, t;
int dp[N];

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
    cin >> n >> m >> t;
    ll A = n - 1, B = m - 1, lim = t;
    if (n == 1 && m == 1) {
        cout << (t + 1) % MOD << el;
        return;
    }
    if (n > 1) lim -= A;
    if (m > 1) lim -= B;
    if (lim < 0) {
        cout << 0 << el;
        return;
    }
    dp[0] = 1;
    if (n > 1) {
        for (int i = A; i <= lim; ++i) {
            dp[i] = (dp[i] + dp[i - A]);
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    if (m > 1) {
        for (int i = B; i <= lim; ++i) {
            dp[i] = (dp[i] + dp[i - B]);
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    
    if (n > 1 && m > 1) {
        ll D = (ll)(n - 1) * (m - 1);
        if (D <= lim) {
             for (int i = D; i <= lim; ++i) {
                dp[i] = (dp[i] + dp[i - D]);
                if (dp[i] >= MOD) dp[i] -= MOD;
            }
        }
    }
    ll ans = 0;
    for (int v = 0; v <= lim; ++v) {
        ll ways = dp[v];
        ll val = (lim - v + 1) % MOD;
        ans = (ans + ways * val) % MOD;
    }
    
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}