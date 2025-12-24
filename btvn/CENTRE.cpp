#include <bits/stdc++.h>
using namespace std;

#define task "CENTRE"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

int n, m;
ll dist[M][M];
vector<pair<ll, pll>> edges;
vpll ans;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void floyd(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dist[i][j] = (i == j) ? 0 : INF; 
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, val;
        cin >> u >> v >> val;
        dist[u][v] = dist[v][u] = val;
        edges.pb({val, {u, v}});
    }
    floyd();
    for (auto uv : edges){
        ll u = uv.second.first, v = uv.second.second;
        bool prune = 0;
        for (int k = 1; k <= n; k++){
            if (dist[u][v] > dist[u][k] + dist[k][v]){
                prune = 1;
                break;
            }
        }
        if (!prune){
            ans.pb({u, v});
        }
    }
    cout << ans.size() << el;
    for (auto i : ans) cout << i.first << " " << i.second << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
 