#include <bits/stdc++.h>
using namespace std;
#define task "bulls"
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
ll n, k, dp[N];
void tassk(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void solve(){
    cin >> n >> k;
    for (int i = 0; i <= k; i++) dp[i] = i + 1;
    for (int i = k + 1; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - k - 1]) % MOD;
    cout << dp[n];
}
int main()
{
    tassk();
    solve();
    return 0;
}