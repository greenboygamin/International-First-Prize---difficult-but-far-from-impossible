#include <bits/stdc++.h>
using namespace std;

#define task "houses"
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

const ll N = 1e5 + 5;
const ll INF = 4e18;

ll n, e[N];
string s[N], r[N];
ll dp[N][2];

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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> e[i];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        r[i] = string(s[i].rbegin(), s[i].rend());
    }
    for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = INF;
    dp[1][0] = 0;
    dp[1][1] = e[1];
    for (int i = 2; i <= n; i++) {
        if (s[i] >= s[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i] >= r[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (r[i] >= s[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + e[i]);
        if (r[i] >= r[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + e[i]);
    }
    ll ans = min(dp[n][0], dp[n][1]);
    if (ans >= INF / 2) cout << -1 << el;
    else cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
