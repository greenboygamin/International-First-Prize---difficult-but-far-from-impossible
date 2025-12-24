#include <bits/stdc++.h>
using namespace std;
#define task "BISLAND"
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
const ll M = 1e4 + 2;
const ll MOD = 2111992;
ll n, m, t, x, y;
bool visited[M];
vll adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll bfs(){
    memset(visited, 0, sizeof(visited));
    visited[1] = 1;
    queue<pll> q;
    q.push({1, 0});
    while (!q.empty()){
        ll u = q.front().first;
        ll len = q.front().second;
        q.pop();
        if (u == n) return len;
        for (auto v : adj[u]){
            if (!visited[v]){
                visited[v];
                q.push({v, len + 1});
            }
        }
    }
    return -1;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll ans = bfs();
    cout << ans << el;
}
int main() {
    tassk();
    cin >> t;
    while (t--)
    solve();
    return 0;
}