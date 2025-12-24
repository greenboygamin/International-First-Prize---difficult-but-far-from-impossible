#include <bits/stdc++.h>
using namespace std;
#define task "HIGHWAY"
#define ll long long int
#define ld long double
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
ll n, m, x[N], y[N];
ld d[N];
ll dem = 0;
bool check[M][M];
bool visited[N];
vector<pair<ll, ld>> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void prim(){
    vpll ans;
    vll trace(N, -1);
    pq<pair<ld, ll>, vector<pair<ld, ll>>, greater<pair<ld, ll>>> kiu;
    fill(d, d + N, 1e9);
    memset(visited, 0, sizeof visited);
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
            if (d[v] > val && !visited[v]){
                d[v] = val;
                trace[v] = u;
                kiu.push({d[v], v});
            }
        }
    }
    ll count = 0;
    for (auto i : ans){
        if (!check[i.first][i.second]) count++;
    }
    cout << count << el;
    for (auto i : ans){
        if (!check[i.first][i.second]) cout << i.first << " " << i.second << el;
    }
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int xcoor, ycoor;
        cin >> xcoor >> ycoor;
        ld dis = 0;
        adj[xcoor].pb({ycoor, dis});
        adj[ycoor].pb({xcoor, dis});
        check[xcoor][ycoor] = check[ycoor][xcoor] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!check[i][j] && i != j){
                int xcoor = i, ycoor = j;
                ld dis = sqrt(((ld)x[xcoor] - (ld)x[ycoor]) * ((ld)x[xcoor] - (ld)x[ycoor]) + ((ld)y[xcoor] - (ld)y[ycoor]) * ((ld)y[xcoor] - (ld)y[ycoor]));
                adj[xcoor].pb({ycoor, dis});
                adj[ycoor].pb({xcoor, dis});
            }
        }
    }
    prim();
}

int main() {
    tassk();
    solve();
    return 0;
}