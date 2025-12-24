#include <bits/stdc++.h>
using namespace std;

#define task "SEQ"
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

const ll N_MAX = 1e5 + 7; 
const int K_MAX = 25;
const ll INF = 1e18;

int n, k;
int a[N_MAX];
ll dp[N_MAX][K_MAX];
int freq[N_MAX]; 

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0; 
    for (int ki = 1; ki <= k; ++ki) {
        for (int i = 1; i <= n; ++i) {
            ll cur = 0;
            for(int v = 1; v <= n; ++v) freq[v] = 0;
            for (int j = i; j >= 1; --j) {
                int val = a[j];
                cur += freq[val];
                freq[val]++;
                if (dp[j - 1][ki - 1] != INF) {
                    dp[i][ki] = min(dp[i][ki], dp[j - 1][ki - 1] + cur);
                }
            }
        }
    }

    cout << dp[n][k] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}