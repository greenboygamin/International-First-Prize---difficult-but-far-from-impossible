#include <bits/stdc++.h>
using namespace std;
#define task "transmission"
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
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, m, x[N], y[N], p[N];
vector<ll> adj[N];
bool visited[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll cal(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
ll bfs(ll start){
    qll q;
    q.push(start);
    visited[start] = 1;
    ll count = 1;
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (!visited[v]){
                visited[v] = 1;
                q.push(v);
                count++;
            }
        }
    }
    return count;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> p[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ll dis = cal(x[i], y[i], x[j], y[j]);
            if (p[i] * p[i] >= dis){
                adj[i].pb(j);
            }
        }
    }
    ll maxs = INT_MIN;
    for (int i = 1; i <= n; i++){
        memset(visited, 0, sizeof visited);
        maxs = max(maxs, bfs(i));
    }
    cout << maxs;
}

int main() {
    tassk();
    solve();
    return 0;
}
