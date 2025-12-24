#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define task "ZAM"
#define ll long long int
#define pll pair<ll, ll>
#define pb push_back
const ll N = 1e6 + 2;
const ll INF = 1e9 + 7;

ll n, m, w, k, s, c[N];
vector<pll> adj[N];
vector<bool> visited(N, 0);
vector<ll> trace(N, -1);

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void bfs(){
    queue<pll> q;
    q.push({c[w], w});
    visited[w] = 1;

    while (!q.empty()){
        ll cost = q.front().first;
        ll u = q.front().second;
        q.pop();
        if (u == k && cost == s) return;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            ll news = cost + val;
            if (!visited[v] && news <= s){
                visited[v] = 1;
                trace[v] = u; 
                q.push({news, v});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> w >> k >> s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].pb({y, c[y]});
        adj[y].pb({x, c[x]});
    }

    bfs();

    if (trace[k] != -1) {
        vector<ll> path;
        for (ll v = k; v != -1; v = trace[v]) {
            path.pb(v);
        }
        reverse(path.begin(), path.end());
        for (ll room : path) {
            cout << room << " ";
        }
        cout << el;
    } else {
        cout << "IMPOSSIBLE" << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
