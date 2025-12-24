

#include <bits/stdc++.h>
using namespace std;

#define task "AVERAGE"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 5e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll n, k, S, a[N], dp[M][M];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void Solve() {
    cin >> n >> k;
    int max_s = n * 300; 

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1; 
    for (int i = 1; i <= n; ++i) {
        int a_i = a[i];
        for (int j = i; j >= 1; --j) {
            for (int s = max_s; s >= a_i; --s) {
                dp[j][s] = (dp[j][s] + dp[j-1][s - a_i]) % MOD;
            }
        }
    }

    ll res = 0;
    
    for (int L = 1; L <= n; ++L) {
        int S = L * k;
        if (S <= max_s) {
            res = (res + dp[L][S]) % MOD;
        }
    }

    cout << res << el;
}

int main() {
    Task(); int t; cin >> t; while (t--)
    Solve();
    return 0;
}
