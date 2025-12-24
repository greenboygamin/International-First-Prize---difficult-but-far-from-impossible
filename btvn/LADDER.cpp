#include <bits/stdc++.h>
using namespace std;
#define task "LADDER"
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
ll n, m, k, dp[N], u, v;
ll a[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> m >> n;
    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> v >> u;
        a[v] = max(a[v], u);
    }
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    dp[3] = max({a[1], a[2], a[3]});
    for (int i = 4; i <= n; i++){
        dp[i] = min({dp[i - 2] + max(a[i], a[i - 1]), dp[i - 1] + a[i], dp[i - 3] + max({a[i], a[i - 1], a[i - 2]})});
    }
    cout << dp[n];
}
int main() {
    tassk();
    solve();
    return 0;
}