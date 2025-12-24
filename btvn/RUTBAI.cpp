#include <bits/stdc++.h>
using namespace std;
#define task "RUTBAI"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e6;
ll n, dp[1007][1007], a[N];
vll v;
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
        cin >> a[i];
    }
    int j;
    for (int len = 2; len < n; len++){
        for (int i = 1; i + len <= n; i++){
            j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++){
                dp[i][j] = min(dp[i][j], a[i] * a[k] * a[j] + dp[i][k] + dp[k][j]);
            }
        }
    }
    cout << dp[1][n];
}
int main()
{
    tassk();
    solve();
    return 0;
}
