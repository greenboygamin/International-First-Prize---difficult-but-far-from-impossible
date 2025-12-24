#include <bits/stdc++.h>
using namespace std;

#define task "BLUEGRAPH"
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
const ll M = 5e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 1e6;

int n, m, q;
int d[M][M]; // dist[u][v]
vi adj[N];
vi blue[N];
int dist[N];
int query[N];
bool ban[N];
bool prune[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void bfs(int u){
    memset(d[u], -1, sizeof d[u]);
    d[u][u] = 0;
    queue<int> qu;
    qu.push(u);
    while (!qu.empty()){
        int cu = qu.front(); qu.pop();
        for (auto v : adj[cu]){
            if (d[u][v] == -1){
                d[u][v] = d[u][cu] + 1;
                qu.push(v);
            }
        }
    }
}

void multisource_bfs(){
    memset(dist, -1, sizeof dist);
    queue<int> qu;
    for (int i = 1; i <= n; i++){
        if (ban[i]){
            dist[i] = 0;
            qu.push(i);
        }
    }
    while (!qu.empty()){
        int u = qu.front(); qu.pop();
        for (auto v : adj[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
}

void Solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++){
        bfs(i);
    }
    for (int i = 1; i <= q; i++){
        int u, val; cin >> u >> val;
        query[u] = val;
    }
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++){
            if (d[u][v] < query[u]){
                ban[v] = 1;
            }
        }
    }
    multisource_bfs();
    
    
}

int main() {
    Task();
    Solve();
    return 0;
}


