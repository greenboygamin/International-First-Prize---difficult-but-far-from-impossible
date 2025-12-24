#include <bits/stdc++.h>
using namespace std;
#define task "BOTTLES"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], dp[N], x[N], dem = 0;
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 0; dp[1] = a[1]; dp[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++){
        dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]});
    }
    ll i = n;
    while (i > 0){
        if (dp[i] == dp[i - 1]){
            x[i] = 1;
            i--;
        }
        else if (dp[i] == dp[i - 2] + a[i]){
            x[i - 1] = 1;
            i -= 2;
        }
        else {
            x[i - 2] = 1;
            i -= 3;
        }
    }
    for (int i = 1; i <= n; i++){
        if (x[i] == 0) dem++;
    }
    cout << dem << " " << dp[n] << el;
    for (int i = 1; i <= n; i++){
        if (x[i] == 0) cout << i << el;
    }
}
int main()
{
    tassk();
    solve();
    return 0;
}
