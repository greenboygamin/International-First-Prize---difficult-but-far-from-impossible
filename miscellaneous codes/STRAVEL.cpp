#include <bits/stdc++.h>
using namespace std;
#define task "STRAVEL"
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
const ll N = 20; 
const ll M = 2e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n;
string s;
int dp[N][(1 << N)]; 

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 1;
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                if (s[i] == '>') {
                    for (int j = i + 1; j < n; j++) {
                        if (!((mask >> j) & 1)) {
                            int next_mask = mask | (1 << j);
                            dp[j][next_mask] += dp[i][mask];
                            if (dp[j][next_mask] >= MOD) dp[j][next_mask] -= MOD;
                        }
                    }
                } else { 
                    for (int j = 0; j < i; j++) {
                        if (!((mask >> j) & 1)) { 
                            int next_mask = mask | (1 << j);
                            dp[j][next_mask] += dp[i][mask];
                            if (dp[j][next_mask] >= MOD) dp[j][next_mask] -= MOD;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i][(1 << n) - 1] << (i == n - 1 ? "" : " ");
    }
}

int main() {
    tassk();
    solve();
    return 0;
}