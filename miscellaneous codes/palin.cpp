#include <bits/stdc++.h>
using namespace std;
#define task "palin"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e4 + 2;
const ll MOD = 1e9 + 7;
ll n, dp[5000][5000];
string s;
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
    cin >> n;
    cin >> s;
    s = " " + s;
    for (int len = 1; len < n; len++){
        for (int i = 1; i <= n; i++){
            ll j = i + len;
            dp[i][j] = 1e9;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
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