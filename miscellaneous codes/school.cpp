#include <bits/stdc++.h>
using namespace std;

#define task "SCHOOl"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n, m;
vll cnt(N, 0);
vll d(N, 1e9);
vector<pll> adj[N];
bool visited[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void dijkstra(){
    d[1] = 0;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, 1});
    cnt[1] = 1;
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                cnt[v] = cnt[u];
                kiu.push({d[v], v});
            }
            else if (d[v] == d[u] + val){
                cnt[v] += cnt[u];
                kiu.push({d[v], v});
            }
        }
    }
    cout << d[n] << " " << cnt[n];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int k, u, v, l;
        cin >> k >> u >> v >> l;
        adj[u].pb({v, l});
        if (k == 2) adj[v].pb({u, l});
    }
    dijkstra();
}

int main() {
    tassk();
    solve();
    return 0;
}
 