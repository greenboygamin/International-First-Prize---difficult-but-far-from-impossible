#include <bits/stdc++.h>
using namespace std;

#define task "HOPMAT"
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
#define ld long double

const ll N = 1005;
ll n, m, k, x[N];
vector<ll> adj[N];
bool visited[N];
ll reach[N];

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void bfs(ll start) {
    qll q;
    visited[start] = true;
    q.push(start);
    reach[start]++;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                reach[v]++;
            }
        }
    }
}

void solve() {
    cin >> k >> n >> m;

    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    memset(reach, 0, sizeof(reach));

    for (int i = 1; i <= k; i++) {
        memset(visited, 0, sizeof(visited));
        bfs(x[i]);
    }

    ll count = 0;
    for (int i = 1; i <= n; i++) {
        if (reach[i] == k) count++;
    }

    cout << count << el;
}

int main() {
    init();
    solve();
    return 0;
}
