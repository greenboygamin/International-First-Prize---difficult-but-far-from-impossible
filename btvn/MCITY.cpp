#include <bits/stdc++.h>
using namespace std;
#define task "MCITY"
#define ll long long int
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
ll n, m, k, q, d[N], x;
vll des(N);
bool visited[N];
vector<pll> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void dijkstra(){
    pq<pll, vpll, greater<pll>> kiu;
    fill (d, d + N, 1e9);
    memset(visited, 0, sizeof visited);
    for (auto i : des){
        kiu.push({0, i});
        d[i] = 0;
    }
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
void solve(){
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    des.resize(k + 10);
    for (int i = 1; i <= k; i++) cin >> des[i];
    dijkstra();
    for (int i = 1; i <= q; i++){
        cin >> x;
        cout << d[x] << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}