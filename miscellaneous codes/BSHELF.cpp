#include <bits/stdc++.h>
using namespace std;
#define task "BSHELF"
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
ll n, l, dp[N];
pll a[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    ll wid, high;
    for (int i = 1; i <= n; i++){
        dp[i] = 1e9;
        wid = 0;
        high = 0;
        for (int j = i; j >= 1; j--){
            wid += a[j].second;
            if (wid > l) break;
            high = max(high, a[j].first);
            dp[i] = min(dp[i], dp[j - 1] + high);
        }
    }
    cout << dp[n];
}
int main() {
    tassk();
    solve();
    return 0;
}