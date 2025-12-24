#include <bits/stdc++.h>
using namespace std;
#define task "QBSTR"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
const ll INF = 1e9 + 7;
ll dp[M][M];
string m, n;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve(){
    cin >> m >> n;
    ll x = m.length(), y = n.length();
    m = " " + m;
    n = " " + n;
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= y; j++){
            if (m[i] == n[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[x][y] << el;
}   
int main() {
    tassk();
    solve();
    return 0;
}