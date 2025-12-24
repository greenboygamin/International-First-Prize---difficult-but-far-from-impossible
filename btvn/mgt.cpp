#include <bits/stdc++.h>
using namespace std;
#define task "mgt"
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
ll n, k, x, y, z, d[N];
bool visited[N];
bool check[M][M];
vector<pll> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void prim(){
    vector<pll> news;
    ll sum = 0;
    vll trace(N, -1);
    pq<pll, vpll, greater<pll>> kiu;
    fill (d, d + N, 1e9);
    memset(visited, 0, sizeof visited);
    d[1] = 0;
    kiu.push({0, 1});
    while (!kiu.empty()){
        ll u = kiu.top().second;
        ll gt = kiu.top().first;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        sum += gt;
        if (trace[u] != -1) news.pb({trace[u], u});
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (!visited[v] && d[v] > val){
                d[v] = val;
                trace[v] = u;
                kiu.push({d[v], v});
            }
        }
    }
    cout << sum << el;
    if (sum){
        for (auto i : news){
            if (!check[i.first][i.second]) cout << i.first << " " << i.second << el;
        }
    }
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        cin >> x >> y;
        adj[x].pb({y, 0});
        adj[y].pb({x, 0});
        check[x][y] = check[y][x] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> z;
            if (i != j && !check[i][j]){
                adj[i].pb({j, z});
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