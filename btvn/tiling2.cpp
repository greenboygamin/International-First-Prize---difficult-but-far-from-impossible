#include <bits/stdc++.h>
using namespace std;
#define task "tiling2"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], dp[N];
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
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
    }
    //for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << dp[n];
}
int main()
{
    tassk();
    solve();
    return 0;
}
