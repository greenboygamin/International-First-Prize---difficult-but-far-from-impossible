#include <bits/stdc++.h>
using namespace std;

#define task "FREEBUS"
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
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;
vector<pll> adj[N];
bool visited[N];
ll n, m, s, k, t, d[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
struct copper{
    ll cost, node, used;
    bool operator> (const copper &other) const{
        return cost > other.cost;
    }
};

void dijkstra(ll beg, ll reach){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            d[i][j] = INF;
        }
    }
    //d[i][j]: cost to i having used j tick sususus
    priority_queue<copper, vector<copper>, greater<copper>> kiu;
    d[beg][0] = 0;
    kiu.push({0, beg, 0});
    while (!kiu.empty()){
        ll u = kiu.top().node, cost = kiu.top().cost, used = kiu.top().used;
        if (u == reach) break;
        kiu.pop();
        for (auto cur : adj[u]){
            ll v = cur.first, val = cur.second;
            if (d[v][used] > cost + val){
                d[v][used] = cost + val;
                kiu.push({d[v][used], v, used});
            }
            if (used < k && d[v][used + 1] > cost){
                d[v][used + 1] = cost;
                kiu.push({d[v][used + 1], v, used + 1});
            }
        }
    }
    ll res = INF;
    for (int i = 0; i <= k; i++) res = min(res, d[reach][i]);
    cout << res;
}
void solve() {
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; ++i){
        int x, y, v;
        cin >> x >> y >> v;
        adj[x].pb({y, v});
        adj[y].pb({x, v});
    }
    dijkstra(s, t);
}

int main() {
    tassk();
    solve();
    return 0;
}