#include <bits/stdc++.h>
using namespace std;
#define task "STONES"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, a[N], dp[M][M], prf[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }
    for (int len = 2; len <= n; len++){
        for (int i = 1; i <= n - len + 1; i++){
            ll j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prf[j] - prf[i - 1]);
            }
        }
    }
    cout << dp[1][n];
}
int main() {
    tassk();
    solve();
    return 0;
}