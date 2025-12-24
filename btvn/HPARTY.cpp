#include <bits/stdc++.h>
using namespace std;
#define task "HPARTY"
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
ll n, m;
vll d(N, -1);
vector<ll> adj[N];
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
    q.push(0);
    d[0] = 0;
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs();
    for (int i = 1; i < n; i++){
        cout << d[i] << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}