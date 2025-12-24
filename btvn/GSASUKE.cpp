#include <bits/stdc++.h>
using namespace std;
#define task "GSASUKE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, h[N], dp[N];
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
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[1] = h[1]; dp[2] = h[1] + abs(h[1] - h[2]);
    for (int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + 2 * abs(h[i - 2] - h[i]));
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
