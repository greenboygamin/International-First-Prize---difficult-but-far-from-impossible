#include <bits/stdc++.h>
using namespace std;
#define task "lcs"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
string x, y, a, b, s = ""; ll dp[1001][1001];
vll mot; vll hai;
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
    cin >> a >> b;
    ll m = a.size(), n = b.size();
    x = " " + a; y = " " + b;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (x[i] == y[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    ll i = m, j = n;
    while (i > 0 && j > 0){
        if (x[i] == y[j]){
            s += x[i];
            mot.pb(i);
            hai.pb(j);
            i--; j--;
        }
        else {
            if (dp[i - 1][j] == dp[i][j]) i--;
            else if (dp[i][j - 1] == dp[i][j]) j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << el;
    reverse(mot.begin(), mot.end());
    reverse(hai.begin(), hai.end());
    for (int i = 0; i < mot.size(); i++) cout << mot[i] << " ";
    cout << el;
    for (int i = 0; i < hai.size(); i++) cout << hai[i] << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
