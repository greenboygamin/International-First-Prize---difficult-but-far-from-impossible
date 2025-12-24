#include <bits/stdc++.h>
using namespace std;
#define task "PATH"
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
const ll M = 1e4 + 2;
const ll MOD = 2111992;
ll m, n, u, v, a[M][M];
ll px[] = {0, 0, 1, -1};
ll py[] = {1, -1, 0, 0};
bool visited[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll bfs(){
    visited[u][v] = 1;
    queue<pair<pll, ll>> q;
    q.push({{u, v}, 0});
    while (!q.empty()){
        ll ans = q.front().second;
        ll x = q.front().first.first;
        ll y = q.front().first.second;
        q.pop();
        if (x == 1 || x == m || y == 1 || y == n) return ans + 1;
        for (ll k = 0; k < 4; ++k){
            ll nx = x + px[k];
            ll ny = y + py[k];
            if (1 <= nx && nx <= m && 1 <= ny && ny <= n && !a[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({{nx, ny}, ans + 1});
            }
        }
    }
    return -1;
}
void solve() {
    cin >> m >> n;
    cin >> u >> v;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    ll dem = bfs();
    cout << dem;
}
int main() {
    tassk();
    solve();
    return 0;
}