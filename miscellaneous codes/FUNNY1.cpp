#include <bits/stdc++.h>
using namespace std;
#define task "FUNNY"
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
#define ld long double
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, m, x[N], y[N];
ld d[N];
bool visited[N];
bool check[M][M];
vector<pair<ll, ld>> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ld calc(int i, int j){
    return sqrt(((ld)x[i] - (ld)x[j]) * ((ld)x[i] - (ld)x[j]) + ((ld)y[i] - (ld)y[j]) * ((ld)y[i] - (ld)y[j]));
}

void prim(){
    pq<pair<ll, ld>, vector<pair<ll, ld>>, greater<pair<ll, ld>>> kiu;
    memset(visited, 0, sizeof visited);
    fill(d, d + N, 1e9);
    vll trace(N, -1);
    vpll ans;
    d[1] = 0;
    kiu.push({0, 1});
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        if (trace[u] != -1) ans.pb({trace[u], u});
        for (auto cur : adj[u]){
            ll v = cur.first;
            ld val = cur.second;
            if (!visited[v] && d[v] > val){
                d[v] = val;
                trace[v] = u;
                kiu.push({d[v], v});
            }
        }
    }
    ll dem = 0;
    ld sum = 0;
    for (int i = 2; i <= n; i++) {
        if (!check[trace[i]][i]){
            sum += d[i];
            dem++;
        }
    }
    cout << dem << " ";
    cout << fixed << setprecision(6) << sum;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            adj[i].pb({j, calc(i, j)});
            adj[j].pb({i, calc(i, j)});
        }
    }
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        check[u][v] = 1;
        adj[u].pb({u, 0});
        adj[v].pb({v, 0});
    }
    prim();
    cout << el;
}

int main() {
    tassk();
    solve();
    return 0;
}