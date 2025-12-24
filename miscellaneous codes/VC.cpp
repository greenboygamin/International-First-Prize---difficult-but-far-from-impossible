#include <bits/stdc++.h>
using namespace std;
#define task "VC"
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
ll n, m, x, y, tmp[N], ans = 0;
vll adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll bfs(ll u, ll v){
    qll q;
    q.push(u);
    vll dis(N, -1);
    dis[u] = 0;
    while (!q.empty()){
        ll a = q.front();
        q.pop();
        for (auto b : adj[a]){
            if (dis[b] == -1){
                dis[b] = dis[a] + 1;
                q.push(b);
                if (b == v){
                    return dis[b];
                }
            }
        }
    }
    return -1;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i < n; i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= m; ++i) cin >> tmp[i];
    for (int i = 2; i <= m; ++i){
        ll dem = bfs(tmp[i - 1], tmp[i]);
        if (dem != -1) ans += dem;
    }
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}