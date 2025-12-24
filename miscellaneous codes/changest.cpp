#include <bits/stdc++.h>
using namespace std;
#define task "changest"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 1e9 + 7;
ll dp[M][M];
string x, y;
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
void solve(){
    cin >> x >> y;
    int n = x.length(), m = y.length();
    x = " " + x;
    y = " " + y;
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (x[i] == y[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }
    cout << dp[n][m] << el;
    ll i = n, j = m;
    ll minus = 0;
    vector<string> ans;
    while (i > 0 || j > 0){
        if (x[i] == y[j]){
            i--; j--;
        }
        else {
            if (i > 0 and dp[i][j] == dp[i - 1][j] + 1){
                ans.pb("D " + to_string(i));
                i--;
            }
            else if (j > 0 and dp[i][j] == dp[i][j - 1] + 1){
                ans.pb("I " + to_string(i + 1) + " "+ y[j]);
                j--;
            }
            else if (i > 0 and j > 0 and dp[i][j] == dp[i - 1][j - 1] + 1){
                ans.pb("R " + to_string(i) + " " + y[j]);
                i--; j--;
            }
        }
    }
    for (auto i : ans) cout << i << el;
}
int main()
{
    tassk();
    solve();
    return 0;
}