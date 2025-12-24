#include <bits/stdc++.h>
using namespace std;
#define task "ROAD"
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
ll n, r, u, v, t, d[N];
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
    vll trace(N, -1);
    vpll ans;
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        if (trace[u] != -1) ans.pb({trace[u], u});
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (!visited[v] && d[v] > val){
                d[v] = val;
                trace[v] = u;
                kiu.push({d[v], v});
            }
        }
    }
    ll sum = 0, maxs = 0;
    for (int i = 1; i <= n; i++){
        sum += d[i];
        maxs = max(maxs, d[i]);
    }
    for (auto i : ans) cout << i.first << " " << i.second << el;
    cout << "So tuyen duong: " << ans.size() << el;
    cout << "Thoi gian hoan thanh theo phuong an 2: " << maxs << " (don vi thoi gian)" << el;
    cout << "Hoan thanh som hon: " << sum - maxs << " (don vi thoi gian)";
}
void solve(){
    cin >> n >> r;
    for (int i = 1; i <= r; i++){
        cin >> u >> v >> t;
        adj[u].pb({v, t});
        adj[v].pb({u, t});
    }
    prim();
}

int main() {
    tassk();
    solve();
    return 0;
}