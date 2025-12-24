#include <bits/stdc++.h>
using namespace std;
#define task "TFRIENDS"
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
ll n, t, u, v;
vll des(N);
vll dis(N, -1);
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
    queue<ll> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs();
    ll mins = 1e9, idx = 1e9;
    cin >> t;
    while (t--){
        int tp; cin >> tp;
        if (dis[tp] < mins || (dis[tp] == mins && tp < idx)){
            mins = dis[tp];
            idx = tp;
        }     
    }
    cout << idx;
}

int main() {
    tassk();
    solve();
    return 0;
}