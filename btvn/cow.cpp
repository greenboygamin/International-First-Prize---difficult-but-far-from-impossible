#include <bits/stdc++.h>
using namespace std;
#define task "cow"
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
ll n, m, s, u, v;
vector<ll> adj[N];
bool visited[N];
bool check[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void bfs(){
    qll q;
    q.push(1);
    visited[1] = 1;
    check[1] = 1;
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (!visited[v]){
                q.push(v);
                visited[v] = 1;
                check[v] = 1;
            }
        }
    }
    ll kt = 1;
    for (int i = 1; i <= n; i++){
        if (!check[i]) {
            cout << i << el;
            kt = 0;
        }
    }
    if (kt == 1) cout << 0;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs();
    
    
}

int main() {
    tassk();
    solve();
    return 0;
}
