#include <bits/stdc++.h>
using namespace std;
#define task "NOIDIEM"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e6;
ll n, dp[N], tv[N], a[N], x[N];
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
    dp[0] = 0; a[n + 1] = n + 1;
    for (int i = 1; i <= n + 1; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[i] > a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                tv[i] = j;
            }
        }
    }
    ll maxs = INT_MIN, dem = 0, pos = n + 1;
    cout << dp[n + 1] - 1 << el;
    while (pos > 0){
        dem++;
        x[dem] = tv[pos];
        pos = tv[pos];
    }
    for (int i = 1; i < dem; i++){
        cout << a[x[i]] << " " << x[i] << el;
    }
}
int main()
{
    tassk();
    solve();
    return 0;
}
