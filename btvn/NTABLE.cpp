#include <bits/stdc++.h>
using namespace std;
#define task "NTABLE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e3 + 2;
ll n, a[10000], b[10000], dp[N][N], s = 0, ans = 1e9, res = 1e9;
//code cua HoaRoiCuaPhatVanVatCuiDau
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
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        s += a[i] + b[i];
    }
    //dp[i][j]: min step to i block, sum j
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= s; j++){
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = s; j >= a[i]; j--) dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
        for (int j = s; j >= b[i]; j--) dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + 1);
    }
    for (ll j = 0; j <= s; j++){
        if (dp[n][j] < 1e9){
            if (ans > abs(s - 2 * j)){
                ans = abs(s - 2 * j);
                res = dp[n][j];
            }
            else if (ans == abs(s - 2 * j)){
                res = min(res, dp[n][j]);
            }
        }
    }
    cout << ans << el << res;
}
int main()
{
    tassk();
    solve();
    return 0;
}
