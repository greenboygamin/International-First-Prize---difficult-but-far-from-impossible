#include <bits/stdc++.h>
using namespace std;

#define task "COMNET"
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

const ll N = 3e5 + 5; // Adjusting to handle larger constraints
const ll MOD = 2111992;

ll n, m, s, u, v, d[N];
vector<ll> adj[N];
bool visited[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".INP", "r")) {
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
}

void bfs(){
    qll q;
    q.push(1);
    d[1] = 0;

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
    
    if (d[n] != -1) {
        cout << d[n] + 1 << el;
    } else {
        cout << -1 << el;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        adj[u].pb(v);
    }
    fill(d, d + N, -1);
    bfs();
}

int main() {
    tassk();
    solve();
    return 0;
}
