#include <bits/stdc++.h>
using namespace std;
#define task "STRDEL"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e3 + 2;
ll n, dp[N][N], ans = 1e9, res = 1e9;
string s = " ", s1;
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
    cin >> s1;
    n = s1.size();
    s += s1;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) dp[i][j] = 1;
        }
    }
    ll j;
    for (int l = 2; l <= n - 1; l++){
        for (int i = 1; i <= n - l; i++){
            j = i + l;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else {
                
                for (int k = i; k <= j; k++){
                    dp[i][j] = min(dp[i][k] + dp[k + 1][j], dp[i][j]);
                }
            }
        }
    }
    cout << dp[1][n] << el;
}
int main()
{
    tassk();
    int t; cin >> t; while(t--) solve();
    return 0;
}
