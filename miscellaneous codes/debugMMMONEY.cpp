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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll n, s, dp[3 * M][3 * M], a[N], b[N];
vector<ll> coins[60007];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll add(ll a, ll b){
    a += b; if (a > MOD) a -= MOD; return a;
}

ll sub(ll a, ll b){
    a -= b; if (a <= 0) a += MOD; return a;
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
        for (int k = 0; k <= a[i]; k++){
            for (int j = s; j >= b[i] * k; j--){
                dp[i][j] = add(dp[i][j], dp[i - 1][j - b[i] * k]);
            }
        }   
    }
    cout << dp[n][s] << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
