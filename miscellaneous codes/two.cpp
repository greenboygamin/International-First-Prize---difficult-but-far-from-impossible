#include <bits/stdc++.h>
using namespace std;

#define task "two"
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
const ll N = 3e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 998244353;

ll delta, n, m, deg[N];
vector<int> adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> delta >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans += (deg[i] * (deg[i] - 1));
    }
    cout << ans;
}


int main() {
    tassk();
    solve();
    return 0;
}   