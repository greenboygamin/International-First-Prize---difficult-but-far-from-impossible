#include <bits/stdc++.h>
using namespace std;
#define task "HIGHT"
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
vector<pll> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
bool bfs(ll s, ll t, ll h, ll n){
    vector<bool> visited(n + 1, 0);
    visited[s] = 1;
    qll q;
    q.push(s);
    while (!q.empty()){
        ll cur = q.front();
        q.pop();
        for (auto i : adj[cur]){
            ll a = i.first;
            ll b = i.second;
            if (!visited[a] && b >= h){
                visited[a] = 1;
                q.push(a);
                if (a == t) return true;
            }
        }
    }
    return false;
}
void solve() {
    cin >> n >> s >> t;
    while (cin >> i >> j >> h){
        adj[i].pb({j, h});
        adj[j].pb({i, h});
    }
    ll l = 0, r = 6000, ans = -1;
    while (l <= r){
        ll mid = (l + r) / 2;
        if (bfs(s, t, mid, n)){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    if (ans == -1) cout << "NO SOLUTION";
    else cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}