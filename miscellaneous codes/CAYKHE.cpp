#include <bits/stdc++.h>
using namespace std;
#define task "CAYKHE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
ll n, m, v[N], w[N], dp[1001][1001];
vll ans;
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]){
                if (dp[i][j] < dp[i - 1][j - w[i]] + v[i]){
                    dp[i][j] = dp[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }
    cout << dp[n][m] << el;
    ll i = n, j = m;
    while (i > 0){
        if (dp[i][j] == dp[i - 1][j]){
            i--;
        }
        else {
            ans.pb(i);
            j -= w[i];
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for (auto i : ans) cout << i << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
