#include <bits/stdc++.h>
using namespace std;

#define task "message"
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
const ll N = 600005; 
const ll INF = 1e18; 
const ll MOD = 1e8;
int n, m, s, t;
struct edge {
    ll f;
    int id;
};

vector<pll> adj[N]; 
ll d[N];
int ki[N]; 
vector<edge> nodes[200005]; 

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

bool ss(const edge &a, const edge &b){
    return a.f < b.f;
}

void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        ll u, v, w, f;
        cin >> u >> v >> w >> f;
        int id_u = 2 * i, id_v = 2 * i + 1;
        ki[id_u] = u; ki[id_v] = v;
        nodes[u].pb({f, id_u}); nodes[v].pb({f, id_v});
        adj[id_u].pb({id_v, w}); adj[id_v].pb({id_u, w});
    }
    for (int i = 1; i <= n; ++i) {
        sort(nodes[i].begin(), nodes[i].end(), ss);
        for (int j = 0; j + 1 < nodes[i].size(); ++j) {
            int u_new = nodes[i][j].id, v_new = nodes[i][j + 1].id;
            //cout << u_new << " " << v_new << el;
            ll cost = nodes[i][j + 1].f - nodes[i][j].f;
            adj[u_new].pb({v_new, cost}); adj[v_new].pb({u_new, cost});
        }
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < 2 * m; ++i) d[i] = INF;
    for (auto& e : nodes[s]) {
        int id = e.id, tg = (id % 2 == 0) ? (id + 1) : (id - 1);
        //cout << id << " " << tg << el;
        ll weight = 0;
        for(auto& p : adj[id]) {
            if(p.first == tg) {
                weight = p.second;
                break;
            }
        }
        //cout << weight << el;
        if (d[tg] > weight) {
            d[tg] = weight;
            pq.push({d[tg], tg});
            // cout << "node: " << tg << "--->" << "d = " << d[tg] << el;
        }
    }
    while (!pq.empty()) {
        ll cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (cost > d[u]) continue;
        if (ki[u] == t) {
            cout << cost << el;
            return;
        }
        for (auto& e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    cout << -1 << el;
}

int main() {
    tassk();
    solve();
    return 0;
}

/*
.█████       █████  █████   █████████  █████   ████ █████ █████
▒▒███       ▒▒███  ▒▒███   ███▒▒▒▒▒███▒▒███   ███▒ ▒▒███ ▒▒███ 
.▒███        ▒███   ▒███  ███     ▒▒▒  ▒███  ███    ▒███  ▒███ 
.▒███        ▒███   ▒███ ▒███          ▒███████     ▒███  ▒███ 
.▒███        ▒███   ▒███ ▒███          ▒███▒▒███    ▒███  ▒███ 
.▒███      █ ▒███   ▒███ ▒▒███     ███ ▒███ ▒▒███   ▒███  ▒███ 
.███████████ ▒▒████████   ▒▒█████████  █████ ▒▒████ █████ █████
▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒ 
*/
