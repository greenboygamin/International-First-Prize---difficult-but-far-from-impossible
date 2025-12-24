#include <bits/stdc++.h>
using namespace std;

#define task "DIJ"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
int n, m, k;
vpii adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

vi dijkstra(int s){
    vi d(n + 1, 1e9);
    priority_queue<pii, vpii, greater<pii>> kiu;
    kiu.push({0, s});
    d[0] = 0;
    while (!kiu.empty()){
        int du = kiu.top().first;
        int u = kiu.top().second;
        kiu.pop();
        if (du > d[u]) continue;
        for (auto cur : adj[u]){
            int v = cur.first;
            int val = cur.second;
            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                kiu.push({d[v], v});
            }
        }
    }
    return d;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int x, y, val;
        cin >> x >> y >> val;
        adj[x].pb({y, val});
    }
    vector<vi> dist(n + 1, vi(n + 1, 1e9));
    for (int i = 1; i <= n; i++){
        dist[i] = dijkstra(i);
    }
    ll primeD = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j){
                primeD += dist[i][j];
            }
        }
    }

    for (int test = 0; test < k; test++){
        int e;
        cin >> e;
        while (e--){
            int u, v, t;
            cin >> u >> v >> t;

            // Add the new edge dynamically
            adj[u].pb({v, t});

            // Recompute shortest path only for affected node 'u'
            vi newDist = dijkstra(u);

            // Update distances and the sum of shortest paths dynamically
            ll newD = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {
                        // If the new path is shorter, update the distance
                        if (newDist[j] < dist[u][j]) {
                            dist[u][j] = newDist[j];
                        }
                        newD += dist[i][j];
                    }
                }
            }

            // Output the new sum after adding the new edge
            cout << newD << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
 