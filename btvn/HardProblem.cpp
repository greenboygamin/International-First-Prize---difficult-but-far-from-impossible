#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll M = 1e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll dp[N][2];
string s[N], s_rev[N];
ll n, c[N];


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
    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
    }
    s[0] = s_rev[0] = "";
    dp[0][0] = 0;
    dp[0][1] = INF;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        string revs = s[i];
        reverse(revs.begin(), revs.end());
        s_rev[i] = revs;
    }
    for (int i = 1; i <= n; i++){
        if (s[i] >= s[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i] >= s_rev[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (s_rev[i] >= s[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (s_rev[i] >= s_rev[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }
    ll ans = min(dp[n][0], dp[n][1]);
    if (ans == INF) cout << -1;
    else cout << ans;
}


int main() {
    Task();
    Solve();
    return 0;
}   