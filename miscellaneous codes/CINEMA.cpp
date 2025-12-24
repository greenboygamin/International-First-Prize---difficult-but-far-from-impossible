#include <bits/stdc++.h>
using namespace std;
#define task "CINEMA"
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
ll n, m, k, s, e, d, f[N], p[N], a[M][M], dp[M][M];
vll phim[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> f[i];
        phim[f[i]].pb(i);
    }
    memset(a, 0x3f, sizeof a);
    for (int i = 1; i <= n; i++) a[i][i] = 0;
    for (int i = 1; i <= m; i++){
        cin >> s >> e >> d;
        a[s][e] = a[e][s] = d;
    }
    for (int z = 1; z <= n; z++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                a[i][j] = min(a[i][z] + a[z][j], a[i][j]);
            }
        }
    }
    for (int i = 1; i <= k; i++){
        cin >> p[i];
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= k; i++){
        if (i == 1){
            for (auto x : phim[p[i]]){
                dp[i][x] = min(dp[i][x], a[1][x]);
            }
        }
        for (auto x : phim[p[i]]){
            for (auto y : phim[p[i - 1]]){
                dp[i][x] = min(dp[i][x], dp[i - 1][y] + a[x][y]);
            }
        }
    }
    ll mins = 0x3f3f3f3f;
    for (auto x : phim[p[k]]){
        mins = min(mins, dp[k][x]);
    }
    cout << mins;
}
int main() {
    tassk();
    solve();
    return 0;
}