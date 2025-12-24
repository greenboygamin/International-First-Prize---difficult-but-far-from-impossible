#include <bits/stdc++.h>
using namespace std;

#define task "sumpath"
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

const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 998244353;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int m, n;
int a[2210][2210];
ll dp[2210][2210], sm[2210][2210];

void solve() {
    cin >> m >> n;
    
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            a[i][j] = s[j-1] - '0';
        }
    }
    
    dp[1][1] = 1;
    sm[1][1] = a[1][1];
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1]) % MOD;
            sm[i][j] = (sm[i-1][j] + sm[i][j-1] + sm[i-1][j-1] + dp[i][j] * a[i][j]) % MOD;
        }
    }
    
    cout << sm[m][n] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}