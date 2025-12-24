#include <bits/stdc++.h>
using namespace std;

#define task "MMONEY"
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
const ll N = 1e6 + 1;
const ll M = 6e3 + 1;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, s, dp[M][M], a[M], b[M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll add(ll a, ll b){
    a += b; if (a >= MOD) a -= MOD; return a;
}

ll sub(ll a, ll b){
    a -= b; if (a < 0) a += MOD; return a;
}

ll mul(ll a, ll b){
    return 1LL * a * b % MOD;
}

void solve() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int k = b[i]; k <= s; k ++){
            dp[i - 1][k] = add(dp[i - 1][k], dp[i - 1][k - b[i]]);
        }    
        for (int j = 0; j <= s; j++){
            if (j - b[i] * (a[i] + 1) >= 0) dp[i][j] = sub(dp[i][j], dp[i - 1][j - b[i] * (a[i] + 1)]);
            dp[i][j] = add(dp[i][j], dp[i - 1][j]);
        }
        // sum(dp[i - 1][j], j: s - b[i] * a[i] -> s)
    }
    cout << dp[n][s] << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
