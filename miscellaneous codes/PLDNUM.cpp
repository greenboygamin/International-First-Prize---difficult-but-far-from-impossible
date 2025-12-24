#include <bits/stdc++.h>
using namespace std;
#define task ""
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
const ll MOD = 1e9 + 7;

string s, t;
ll dp[100005][10];
ll sumk[100005];
ll memo[100005][11][2];

void pre() {
    memset(dp, 0, sizeof(dp));
    memset(sumk, 0, sizeof(sumk));

    for (int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }
    for (int j = 0; j <= 9; j++) {
        sumk[1] = (sumk[1] + dp[1][j]) % MOD;
    }

    int maxk = (100000 + 1) / 2;
    for (int i = 2; i <= maxk; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int p = 0; p <= 9; p++) {
                if (abs(p - j) >= 5) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][p]) % MOD;
                }
            }
        }
        for (int j = 0; j <= 9; j++) {
            sumk[i] = (sumk[i] + dp[i][j]) % MOD;
        }
    }
}

ll dfs(int pos, int last, bool tight) {
    if (pos == t.length()) {
        return 1;
    }
    if (memo[pos][last + 1][tight] != -1) {
        return memo[pos][last + 1][tight];
    }

    ll res = 0;
    int lim = tight ? (t[pos] - '0') : 9;

    for (int d = 0; d <= lim; d++) {
        if (pos == 0 && d == 0) continue;
        if (last != -1 && abs(d - last) < 5) continue;

        res = (res + dfs(pos + 1, d, tight && (d == lim))) % MOD;
    }

    return memo[pos][last + 1][tight] = res;
}

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
    pre();
    cin >> s;
    int n = s.length();
    ll ans = 0;

    for (int len = 1; len < n; len++) {
        if (len % 2 == 1) {
            if (len == 1) {
                ans = (ans + 9) % MOD;
            } else {
                int k = (len + 1) / 2;
                ans = (ans + sumk[k]) % MOD;
            }
        }
    }

    if (n % 2 == 0) {
        cout << ans << el;
        return;
    }

    int k = (n + 1) / 2;
    t = s.substr(0, k);
    string p = t;
    string tmp = t;
    tmp.pop_back();
    reverse(tmp.begin(), tmp.end());
    p += tmp;

    if (p > s) {
        int i = t.length() - 1;
        while (i >= 0 && t[i] == '0') {
            t[i] = '9';
            i--;
        }
        t[i]--;
    }

    memset(memo, -1, sizeof(memo));
    ans = (ans + dfs(0, -1, true)) % MOD;
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}