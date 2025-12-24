#include <bits/stdc++.h>
using namespace std;
#define task "dayk"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, k, a[N], dp[1001][1001];
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
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] %= k;
    }
    memset(dp, -63, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < k; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] + k) % k] + 1);
        }
    }
    cout << dp[n][0];
}
int main()
{
    tassk();
    solve();
    return 0;
}