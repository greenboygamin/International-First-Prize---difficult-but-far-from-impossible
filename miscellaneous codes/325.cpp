#include <bits/stdc++.h>
using namespace std;

#define task "d13jobshop"
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
const ll B = 131;
const ll INF = INT_MAX;
const ll MOD = 998244353;

ll n, a[N], dp[N][2], l[N], r[N];
vi adj[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

int calc(int val1, int val2){
    return abs(val1 - val2);
}

void dfs(int u, int p){
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        //1: tai u la l, 0: tai u la r
        dp[u][1] += max({dp[v][0] + abs(l[u] - r[v]), dp[v][1] + abs(l[u] - l[v])});
        dp[u][0] += max({dp[v][0] + abs(r[u] - r[v]), dp[v][1] + abs(r[u] - l[v])});
    }
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    dfs(1, -1);
    //for (int i = 1; i <= n; i++) cout << dp[i][1] << " " << dp[i][0] << el;
    cout << max(dp[1][0], dp[1][1]) << el;
}

int main() {
    Task();
    Solve();
    return 0;
}   