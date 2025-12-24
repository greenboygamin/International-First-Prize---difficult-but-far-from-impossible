#include <bits/stdc++.h>
using namespace std;
#define task "GARBAGE"
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
ll n, m, a[M][M], dp[M][M];
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + a[i][j];
        }
    }
    ll i = n, j, maxs = INT_MIN;
    for (int z = 1; z <= m; z++){
        if (dp[n][z] > maxs){
            maxs = dp[n][z];
            j = z;
        }
    }
    cout << maxs << el;
    vll ans;
    while (i > 0 and j > 0){
        if (dp[i][j] == dp[i - 1][j - 1] + a[i][j]){
            ans.pb(j);
            i--; j--;
        }
        else if (dp[i][j] == dp[i - 1][j] + a[i][j]){
            ans.pb(j);
            i--;
        }
        else {
            ans.pb(j);
            i--; j++;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << el;
}
int main()
{
    tassk();
    solve();
    return 0;
}