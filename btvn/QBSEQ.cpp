#include <bits/stdc++.h>
using namespace std;
#define task "QBSEQ"
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
ll n, k, a[N], dp[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] %= k;
    }
    //dp[i][j]: do dai lon nhat cua day thoa man xet tu a1 -> ai chia k du j
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < k; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] + k) % k] + 1);
        }
    }
    cout << dp[n][0];
}   
int main() {
    tassk();
    solve();
    return 0;
}