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

struct edge{
    int u, v, w;
    edge() {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    int get_oth(int x){
        return u + v - x;
    }
};  
vector<edge> edges;
vector<int> adj[N];
int n, m, k;
bool visited[N];
ll d[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void dijkstra(){
    fill(d, d + N, INF);
    d[1] = 0;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, 1});
    while (!kiu.empty()){
        ll u = kiu.top().second, dist = kiu.top().first;
        kiu.pop();
        if (d[u] != dist) continue;
        visited[u] = 1;
        for (int e_id : adj[u]){
            int v = edges[e_id].get_oth(u);
            int w = edges[e_id].w;
            if (d[v] > d[u] + w && !visited[v]){
                d[v] = d[u] + w;
                kiu.push({d[v], v});
            }
        }
    }
}


void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(edges.size());
        adj[v].pb(edges.size());    
        edges.pb(edge(u, v, w));
    }
    dijkstra();
    if (d[n] < k){
        cout << "No"; return;
    }
    cout << "Yes" << el;
    for (int i = 0; i < m; i++){
        auto [u, v, w] = edges[i];
        if (w){
            cout << min((ll)k, max(d[u], d[v])) << el;
        }
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}
