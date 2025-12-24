#include <bits/stdc++.h>
using namespace std;

#define task "MONEY"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int a, b, n, m, k, c[N];
vll d1(N, 1e9);
vll d2(N, 1e9);
vector<pll> adj[N];
bool visited[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void dijkstra(int start, vll &d){
    memset(visited, 0, sizeof visited);
    d[start] = 0;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, start});
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                kiu.push({d[v], v});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k >> a >> b;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        c[x] = y;
    }
    for (int i = 1; i <= m; i++){
        int u, v, val; 
        cin >> u >> v >> val;
        adj[u].pb({v, val});
        adj[v].pb({u, val});
    }
    dijkstra(a, d1);
    dijkstra(b, d2);
    ll ans = 1e9, pos;
    for (int u = 1; u <= n; u++){
        if (c[u] > 0){
            if (ans > d1[u] + c[u] + d2[u]){
                ans = d1[u] + c[u] + d2[u];
                pos = u;
            }
        }
    }
    cout << ans << " " << pos;
}

int main() {
    tassk();
    solve();
    return 0;
}
 