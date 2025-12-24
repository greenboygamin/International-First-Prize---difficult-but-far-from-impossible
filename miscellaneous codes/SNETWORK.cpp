#include <bits/stdc++.h>
using namespace std;
#define task "SNETWORK"
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
ll n, m, k, q, d[N], c[N];
pq<ll, vll, greater<ll>> ans;
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

void prim(){
    pq<pll, vpll, greater<pll>> kiu;
    memset(visited, 0, sizeof visited);
    fill(d, d + N, 1e9);
    d[1] = 0;
    kiu.push({0, 1});
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (!visited[v] && d[v] > val){
                d[v] = val;
                kiu.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) ans.push(d[i]);
    ll dem = 0, idx = 0;
    while (idx < n){
        dem += ans.top();
        ans.pop();
        idx++;
    }
    cout << dem;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].pb({v, l});
        adj[v].pb({u, l});
    }
    cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> k;
        ans.push(k);
    }
    prim();
}

int main() {
    tassk();
    solve();
    return 0;
}