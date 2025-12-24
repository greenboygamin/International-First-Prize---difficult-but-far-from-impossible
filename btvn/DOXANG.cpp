#include <bits/stdc++.h>
using namespace std;

#define task "DOXANG"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
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
const ll MOD = 2e18;

int n, m, s, st, en;
ll t;
vpll adj[N];
ll dp[1005][2][105];
ll d[105][1005];
ll ans = INF;

struct station{
    int u, c, id;
} stats[N];

int cts[N];

struct state{
    ll cost; int u, type, aux;
    bool operator> (const state &other) const{
        return cost > other.cost;
    }
};

void dijkstra(int idx, int st){
    for (int i = 1; i <= n; i++) d[idx][i] = INF;
    d[idx][st] = 0;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, st});
    while (!kiu.empty()){
        ll du = kiu.top().first; int u = kiu.top().second;
        kiu.pop();
        if (du > d[idx][u]) continue;
        for (auto &e : adj[u]){
            ll w = e.second, v = e.first;
            if (d[idx][v] > d[idx][u] + w){
                d[idx][v] = d[idx][u] + w;
                kiu.push({d[idx][v], v});
            }
        }
    }
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].pb({v, w}); adj[v].pb({u, w});
    }
    fill(cts, cts + N, -1);
    for (int i = 1; i <= s; i++){
        cin >> stats[i].u >> stats[i].c;
        stats[i].id = i;
        cts[stats[i].u] = i;
    }
    cin >> st >> en;
    for (int i = 1; i <= s; i++) dijkstra(i, stats[i].u);
    dijkstra(s + 1, en);
    for (int i = 1; i <= n; i++){
        for (int tt = 0; tt < 2; tt++){
            for (int k = 1; k <= s + 1; k++){
                dp[i][tt][k] = INF;
            }
        }
    }
    priority_queue<state, vector<state>, greater<state>> kiu;
    int ki = cts[st];
    if (ki != -1) {
        dp[st][1][ki] = 0;
        kiu.push({0, st, 1, ki});
    }
    
    while (!kiu.empty()){
        state top = kiu.top(); kiu.pop();
        ll c = top.cost;
        int u = top.u, type = top.type, aux = top.aux;
        if (c > dp[u][type][aux]) continue;
        ll cur = 0;
        if (type == 0){
            if (d[aux][u] > t) continue;
            cur = t - d[aux][u];
        }
        if (type == 1){
            if (d[aux][u] > t) continue;
            cur = d[aux][u];
        }
        if (u == en){
            ans = min(ans, c);
        }
        for (auto &e : adj[u]){
            int v = e.first, w = e.second;
            if (type == 0){
                if (d[aux][v] <= t){
                    if (dp[v][0][aux] > c){
                        dp[v][0][aux] = c;
                        kiu.push({c, v, 0, aux});
                    }
                }
            }
            else {
                if (d[aux][u] == d[aux][v] + w){
                    if (dp[v][1][aux] > c){
                        dp[v][1][aux] = c;
                        kiu.push({c, v, 1, aux});
                    }
                }
            }
        }
        int uu = cts[u];
        if (uu != -1){
            int price = stats[uu].c;
            ll tienxang = (t - cur) * price;
            if (dp[u][0][uu] > c + tienxang){
                dp[u][0][uu] = c + tienxang;
                kiu.push({dp[u][0][uu], u, 0, uu});
            }
            for (int k = 1; k <= s + 1; k++){
                ll req = d[k][u];
                if (req <= t && req > cur){
                    ll add = (req - cur) * price;
                    if (dp[u][1][k] > c + add){
                        dp[u][1][k] = c + add;
                        kiu.push({dp[u][1][k], u, 1, k});
                    }
                }
            }
        }
    }
    cout << ans << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}