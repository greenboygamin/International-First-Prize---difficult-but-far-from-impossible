#include <bits/stdc++.h>
using namespace std;
#define task "CABLE"
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
    for (int i = 1; i < n; i++) cin >> a[i];
    dp[1] = 0; dp[2] = a[1]; dp[3] = a[1] + a[2];
    for (int i = 4; i <= n; i++){
        dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + a[i - 1]);
    }
    cout << dp[n] << el;
    //for (int i = 1; i <= n; i++) cout << dp[i] << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
