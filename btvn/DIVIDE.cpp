#include <bits/stdc++.h>
using namespace std;

#define task "DIVIDE"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
ll n, m, k, dp[M][M], c[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m >> k;
    //dp[i][j]: house i, j bags
    ll tmp;
    for (int j = 0; j <= m; j++) dp[1][j] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int x = max(0LL, j - k); x <= min(m, j + k); x++){
                dp[i][j] += dp[i - 1][x];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++){
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            cout << dp[i][j] << " ";
        }
        cout << el;
    }
    /*
    1 1 1 
    1 2 2 
    1 3 4 

    */
}

int main() {
    tassk();
    solve();
    return 0;
}
 