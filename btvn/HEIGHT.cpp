#include <bits/stdc++.h>
using namespace std;
#define task "HEIGHT"
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
const ll INF = 1e9 + 7;
ll n, m, s, t, i, j, h;
vector<pll> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
bool bfs(ll s, ll t, ll h){
    vector<bool> visited(n + 1, 0);
    qll q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll height = cur.second;
            if (!visited[v] && h <= height){
                visited[v] = 1;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}
void solve(){
    cin >> n >> m >> s >> t;
    for (int k = 1; k <= m; k++){
        cin >> i >> j >> h;
        adj[i].pb({j, h});
        adj[j].pb({i, h});
    }
    ll l = 1, r = INF, res;
    while (l <= r){
        ll mid = l + r >> 1;
        if (bfs(s, t, mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout << res;
}

int main() {
    tassk();
    solve();
    return 0;
}