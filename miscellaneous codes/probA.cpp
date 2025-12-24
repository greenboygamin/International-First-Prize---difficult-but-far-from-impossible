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
typedef long double ld;
const ll N = 3e6 + 5;
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll n, a[N], dp[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(dp, dp + N, INF);
    dp[1] = 0;
    ll maxr = 1;
    for (int i = 1; i <= n; i++){
        for (int j = maxr; j <= i + a[i]; j++){
            dp[j] = min(dp[j], dp[i] + 1);
        }
        maxr = max(maxr, i + a[i]);
    }
    if (dp[n] == INF) cout << -1;
    else cout << dp[n];
}

int main() {
    tassk(); 
    solve();
    return 0;
}
