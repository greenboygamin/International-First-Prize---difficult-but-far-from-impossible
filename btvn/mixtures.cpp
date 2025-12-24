#include <bits/stdc++.h>
using namespace std;

#define task "mixtures"
#define el "\n"
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
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
ll n, dp[M][M], color[M][M], mau[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    memset(dp, 0, sizeof dp);
    memset(color, 0, sizeof color);
    memset(mau, 0, sizeof mau);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> mau[i];
        color[i][i] = mau[i];
    }
    for (int len = 2; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++){
                ll tmp = dp[i][k] + dp[k + 1][j] + color[i][k] * color[k + 1][j];
                if (dp[i][j] > tmp){
                    dp[i][j] = tmp;
                    color[i][j] = (color[i][k] + color[k + 1][j]) % 100;
                }
            }
        }
    }
    cout << dp[1][n] << el;
}

int main() {
    tassk(); int t; cin >> t; while (t--)
    solve();
    return 0;
}
 