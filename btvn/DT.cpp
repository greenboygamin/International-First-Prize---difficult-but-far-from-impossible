#include <bits/stdc++.h>
using namespace std;

#define task "DL"
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
ll n, s, t, i, j, h;
vector<vpll> adj(M);
ll d[M], trace[M];
bool visited[M];
vll ans;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void Dijkstra(){
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, s});
    fill(d, d + M, 1e9);
    d[s] = 0;
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto v : adj[u]){
            ll idx = v.first;
            ll val = v.second;
            if (d[idx] > d[u] + val){
                d[idx] = d[u] + val;
                trace[idx] = u;
                kiu.push({d[idx], idx});
            }
        }
    }
    if (d[t] == 1e9) cout << "NO SOLUTION";
    else {
        cout << d[t] << el;
        ll i = t;
        while (i > 0){
            ans.pb(i);
            i = trace[i];
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " -> ";
    cout << ans[ans.size() - 1];
}
void solve() {
    cin >> n >> s >> t;
    while (cin >> i >> j >> h) {
        adj[i].pb({j, h});
        adj[j].pb({i, h});
    }
    Dijkstra();
}
int main() {
    tassk();
    solve();
    return 0;
}