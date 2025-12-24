#include <bits/stdc++.h>
using namespace std;

#define task "EXCHANGE"
#define el "\n"
typedef long long ll;

map<ll, ll> dp;
ll MOD = 1e9 + 7;

ll p(ll n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp.count(n)) return dp[n];
    
    ll res = (p(n / 2) + p(n - 2)) % MOD;
    
    return dp[n] = res;
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
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        dp.clear();
        cout << p(n) << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}