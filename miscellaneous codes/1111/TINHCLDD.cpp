#include <bits/stdc++.h>
using namespace std;

#define task "TINHCLDD"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;

const ll N = 500005;
const ll M = 1e3 + 5;
const ll INF = 1e18; 
const ll MAX_Z = 100001; 

int n, m, q;
vector<pii> adj[N]; 
ll d[N]; 
int p[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v, z;
        cin >> u >> v >> z;
        adj[u].pb({v, z});
        adj[v].pb({u, z});
    }
    for (int i = 0; i < q; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
    d[1] = MAX_Z; 

    priority_queue<pll> pq; 
    pq.push({d[1], 1});

    while (!pq.empty()) {
        ll qu = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (qu < d[u]) {
            continue; 
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int z = edge.second;
            
            ll q_new = min(qu, (ll)z);

            if (q_new > d[v]) {
                d[v] = q_new;
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << d[p[i]] << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}