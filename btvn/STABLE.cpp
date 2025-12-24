#include <bits/stdc++.h>
using namespace std;
#define task "STABLE"
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
ll dist[N], paths[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    queue<ll> q;
    fill(dist, dist + n + 1, LLONG_MAX);
    dist[s] = 0;
    paths[s] = 1;
    q.push(s);
    
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        
        for (ll neighbor : adj[node]) {
            if (dist[neighbor] == LLONG_MAX) {
                dist[neighbor] = dist[node] + 1;
                paths[neighbor] = paths[node];
                q.push(neighbor);
            } else if (dist[neighbor] == dist[node] + 1) {
                paths[neighbor] += paths[node];
            }
        }
    }
    
    ll stable_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i != s && paths[i] > 1) {
            stable_count++;
        }
    }
    
    cout << stable_count << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
