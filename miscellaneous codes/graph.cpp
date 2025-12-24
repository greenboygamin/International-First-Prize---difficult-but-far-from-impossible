#include <bits/stdc++.h>
using namespace std;

#define task "GRAPH"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
#define qll queue<ll>

unordered_map<ll, vll> adj;
unordered_set<ll> reachable; 
ll m, s, t;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs() {
    qll q;
    unordered_map<ll, bool> visited;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                reachable.insert(v);
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

void solve() {
    cin >> m >> s >> t;

    reachable.insert(s);

    for (int k = 1; k <= m; k++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        
        if (reachable.count(u)) {
            if (bfs()) {
                cout << k << el;
                return;
            }
        }
    }
    
    cout << 0 << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
