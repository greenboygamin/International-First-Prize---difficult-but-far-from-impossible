#include <bits/stdc++.h>
using namespace std;
#define task "TCOST"
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
ll n, m, val, b[N], d[N], s[N], e[N], trace[N];
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
void dijkstra(ll x, ll y){
    memset(visited, 0, sizeof visited);
    memset(trace, 0, sizeof trace);
    pq<pll, vpll, greater<pll>> kiu;
    fill(d, d + N, 1e9);
    kiu.push({0, x});
    d[x] = 0;
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (d[v] > d[u] + val + b[v]){
                d[v] = d[u] + val + b[v];
                if (v == y) d[v] -= b[v];
                trace[v] = u;
                kiu.push({d[v], v});
            }
        }
    }
    cout << d[y] << el;
    /*
    ll tv = y;
    vll ans;
    while (tv > 0){
        ans.pb(tv);
        tv = trace[tv];
    }
    reverse(ans.begin(), ans.end());
    for (auto index : ans) cout << index << " ";
    cout << el;
    */
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> val;
            if (val == -1) val = 1e9;
            adj[i].pb({j, val});
        }
    }
    for (int i = 1; i <= m; i++){
        cin >> s[i] >> e[i];
        dijkstra(s[i], e[i]);
    }
}

int main() {
    tassk();
    solve();
    return 0;
}