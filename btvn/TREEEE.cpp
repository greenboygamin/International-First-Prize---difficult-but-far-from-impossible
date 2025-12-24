#include <bits/stdc++.h>
using namespace std;
#define task "TREEEE"
#define el "\n"
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;
int n, q;
ll a[400005], sum_all = 0;
vector<pair<int, int>> adj[400005];
int par[400005];
bool vis[400005];

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void get_path(int u, int target, int p, vector<int>& path, bool& found) {
    path.pb(u);
    par[u] = p;
    if (u == target) { found = true; return; }
    for (auto& e : adj[u]) {
        if (e.first != p && !found) {
            get_path(e.first, target, u, path, found);
        }
    }
    if (!found) path.pop_back();
}

void get_comp(int u, int ban1, int ban2, vector<int>& nodes, ll& w) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    nodes.pb(u);
    w += a[u];
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& e : adj[cur]) {
            int v = e.first;
            if (v == ban1 || v == ban2 || vis[v]) continue;
            vis[v] = true;
            nodes.pb(v);
            w += a[v];
            q.push(v);
        }
    }
}

ll get_diam(const vector<int>& nodes, int ban1, int ban2) {
    if (nodes.empty()) return 0;
    auto bfs = [&](int start) -> pair<int, int> {
        queue<pair<int, int>> q;
        q.push({start, 0});
        for(int x : nodes) vis[x] = false;
        vis[start] = true;
        pair<int, int> res = {start, 0};
        while(!q.empty()){
            int u = q.front().first;
            int d = q.front().second;
            q.pop();
            if(d > res.second) res = {u, d};
            for(auto& e : adj[u]){
                int v = e.first;
                int w = e.second;
                if(v == ban1 || v == ban2) continue;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push({v, d + w});
                }
            }
        }
        return res;
    };
    pair<int, int> p1 = bfs(nodes[0]);
    pair<int, int> p2 = bfs(p1.first);
    return p2.second;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) { cin >> a[i]; sum_all += a[i]; }
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    cin >> q;
    while (q--) {
        int x, y; ll d; cin >> x >> y >> d;
        vector<int> path;
        bool found = false;
        get_path(x, y, 0, path, found);
        ll ans = -1;

        for (size_t i = 0; i < path.size() - 1; ++i) {
            int u = path[i], v = path[i+1];
            for(int k=1; k<=n; ++k) vis[k] = false;
            
            vector<int> c1, c2;
            ll w1 = 0, w2 = 0;
            
            get_comp(u, v, -1, c1, w1); 
            w2 = sum_all - w1;
            
            if (abs(w1 - w2) <= d) {
                c2.clear();
                for(int k=1; k<=n; ++k) if(!vis[k]) c2.pb(k);
                
                ll d1 = get_diam(c1, v, -1);
                ll d2 = get_diam(c2, u, -1);
                
                if (ans == -1 || d1 * d2 < ans) ans = d1 * d2;
            }
        }
        cout << ans << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}