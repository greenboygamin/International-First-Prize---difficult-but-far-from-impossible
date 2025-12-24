#include <bits/stdc++.h>
using namespace std;
#define task "STEP"
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
const ll MOD = 13051984;
ll n, k, dp[N], x;
bool check[N];
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
    for (int i = 1; i <= k; i++){
        cin >> x;
        check[x] = 1;
    }
    dp[0] = 1;
    if (!check[1]) dp[1] = 1;
    for (int i = 2; i <= n; i++){
        if (!check[i]){
            if (!check[i - 1]) dp[i] = (dp[i] + dp[i - 1]) % MOD;
            if (!check[i - 2]) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
    cout << dp[n];
}
int main()
{
    tassk();
    solve();
    return 0;
}