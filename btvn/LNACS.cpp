#include <bits/stdc++.h>
using namespace std;
#define task "LNACS"
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
const ll MOD = 1e9 + 7;
ll n, m, a[N], b[N], dp[5000][5000];
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i > 1 and j > 1){
                if (a[i] == b[j]) dp[i][j] = dp[i - 2][j - 2] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            else {
                if (a[i] == b[j]) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }
    cout << dp[n][m];
}
int main()
{
    tassk();
    solve();
    return 0;
}