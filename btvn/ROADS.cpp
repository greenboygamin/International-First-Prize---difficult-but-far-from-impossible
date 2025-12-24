#include <bits/stdc++.h>
using namespace std;
#define task "ROADS"
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
ll m, n;
vll adj[N];
bool visited[M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void bfs(int x){
    visited[x] = 1;
    qll q;
    q.push(x);
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    ll x, y;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll dem = 0;
    vll ans;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dem++;
            ans.pb(i);
            bfs(i);
        }
    }
    cout << dem - 1 << el;
    for (int i = 1; i < ans.size(); ++i){
        cout << ans[i - 1] << " " << ans[i] << el;
    }
}
int main() {
    tassk();
    solve();
    return 0;
}