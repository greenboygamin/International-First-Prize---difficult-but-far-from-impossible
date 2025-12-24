#include <bits/stdc++.h>
using namespace std;

#define task "XUNGYEU"
#define ll long long int
#define ld long double
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue

const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
const ll INF = 1e9 + 7;

ll n, m, s, t;
vector<ll> adj[N], rev_adj[N];
vector<ll> dist_from_s(N, INF), dist_from_t(N, INF), ways_s(N, 0), ways_t(N, 0);

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void bfs(ll start, vector<ll> adj[], vector<ll> &dist, vector<ll> &ways) {
    qll q;
    q.push(start);
    dist[start] = 0;
    ways[start] = 1;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ways[v] = ways[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                ways[v] += ways[u];
                ways[v] %= MOD; 
            }
        }
    }
}

void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        ll ui, vi;
        cin >> ui >> vi;
        adj[ui].pb(vi);
        rev_adj[vi].pb(ui);
    }

    bfs(s, adj, dist_from_s, ways_s);
    bfs(t, rev_adj, dist_from_t, ways_t);

    ll total_paths = ways_s[t];  // Total paths from s to t
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i != s && i != t && dist_from_s[i] + dist_from_t[i] == dist_from_s[t] && 
            (ways_s[i] * ways_t[i]) % MOD == total_paths) {
            ans++;
        }
    }

    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
