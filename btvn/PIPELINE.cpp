#include <bits/stdc++.h>
using namespace std;

#define task "PIPELINE"
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
ll n, m, k, d[10 * M][21];
vpll adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

struct copper {
    ll cost, node, used;
    bool operator> (const copper &other) const{
        return cost > other.cost;
    }
};


void dijkstra(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            d[i][j] = INF;
        }
    }
    priority_queue<copper, vector<copper>, greater<copper>> kiu;
    kiu.push({0, 1, 0});
    d[1][0] = 0;
    while (!kiu.empty()){
        ll u = kiu.top().node, cost = kiu.top().cost, used = kiu.top().used;
        kiu.pop();
        if (u == n) break;
        for (int i = 0; i < adj[u].size(); i++){
            ll v = adj[u][i].first;
            ll val = adj[u][i].second;
            if (d[v][used] > cost + val){
                d[v][used] = cost + val;
                kiu.push({d[v][used], v, used});
            }
            if (used < k){
                if (d[v][used + 1] > cost){
                    d[v][used + 1] = cost;
                    kiu.push({d[v][used + 1], v, used + 1});
                }
            }
        }
    }
    ll mins = INF;
    for (int i = 0; i <= k; i++){
        mins = min(mins, d[n][i]);
    }
    cout << mins << el;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int x, y, val;
        cin >> x >> y >> val;
        adj[x].pb({y, val});
        adj[y].pb({x, val});
    }
    dijkstra();
}

int main() {
    tassk();
    solve();
    return 0;
}