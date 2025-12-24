#include <bits/stdc++.h>
using namespace std;
#define task "XAYDUNG"
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
ll n, i, j, m, val, d[N];
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
void prim(){
    pq<pll, vpll, greater<pll>> kiu;
    fill(d, d + N, 1e9);
    memset(visited, 0, sizeof visited);
    d[1] = 0;
    kiu.push({0, 1});
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll weight = cur.second;
            if (!visited[v] && weight < d[v]){
                d[v] = weight;
                kiu.push({d[v], v});
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for (int z = 1; z <= m; z++){
        cin >> i >> j >> val;
        adj[i].pb({j, val});
        adj[j].pb({i, val});
    }
    prim();
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum = max(sum, (d[i]) * (d[i] != 1e9));
    cout << sum;    
}

int main() {
    tassk();
    solve();
    return 0;
}