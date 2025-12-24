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
const ll N = 3e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

ll dist[N], cost[N];
ll n, q, sz[N], par[N], p[N];

vector<pii> adj[N];
vector<pii> edges;
vector<int> query;
bool visited[N];
bool mark[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    for (int i = 1; i <= n; i++){
        par[i] = i;
        cost[i] = INF;
    }
}

int finds(int u){
    return (par[u] == u) ? u : (par[u] = finds(par[u]));
}

void unites(int u, int v){
    u = finds(u); v = finds(v);
    par[v] = u;
    cost[u] = min(cost[u], cost[v]);
}

void bfs(){
    fill(dist, dist + N, INF);
    dist[1] = 0;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, 1});
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first, val = cur.second;
            if (!visited[v] && dist[v] > dist[u] + val){
                dist[v] = dist[u] + val;
                kiu.push({dist[v], v});
            }
        }
    }
    //for (int i = 2; i <= n; i++) cout << i << ": " << dist[i] << el;
}

void solve() {
    cin >> n >> q;
    query.resize(q + 1);
    edges.resize(n + 1);
    for (int i = 2; i <= n; i++){
        int pi, ci;
        cin >> pi >> ci;
        adj[i].pb({pi, ci});
        adj[pi].pb({i, ci});
        edges[i] = {pi, i};
    }
    bfs();
    init();
    for (int i = 2; i <= n; i++){
        if (adj[i].size() == 1) cost[i] = dist[i]; 
    }
    for (int i = 1; i <= q; i++){
        cin >> query[i];
        mark[query[i]] = 1;
    }
    for (int i = 2; i <= n; i++){
        if (!mark[i]) unites(edges[i].first, edges[i].second);
        //cout << edges[i].first << " " << edges[i].second << el;
    }
    vector<ll> ans;
    for (int i = q; i >= 1; --i){
        if (cost[1] == INF) ans.pb(-1);
        else ans.pb(cost[1]);
        unites(edges[query[i]].first, edges[query[i]].second);
        //cout << edges[query[i]].first << " " << edges[query[i]].second << el;
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << el;
}


int main() {
    tassk();
    solve();
    return 0;
}   