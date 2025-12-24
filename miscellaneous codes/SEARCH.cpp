#include <bits/stdc++.h>
using namespace std;
#define task "SEARCH"
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
ll n, m, q, a, b, c, d[N], trace[N];
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
            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                trace[v] = u;
                kiu.push({d[v], v});
            }
        }
    }
}
void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    for (int i = 1; i <= q; i++){
        cin >> a >> b >> c;
        dijkstra(b, c);
        if (a == 1){
            cout << d[c] << el;
        }
        if (a == 2){
            vll ans;
            ll i = c;
            while (i >= b){
                ans.pb(i);
                i = trace[i];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << " ";
            for (auto i : ans) cout << i << " "; cout << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}