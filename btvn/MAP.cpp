#include <bits/stdc++.h>
using namespace std;
#define task "MAP"
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
ll n, a[M][M];
ll px[] = {1, -1, 0, 0};
ll py[] = {0, 0, 1, -1};
bool visited[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll dfs(ll x, ll y){
    stack<pll> s;
    s.push({x, y});
    visited[x][y] = 1;
    ll size = 0;
    while (!s.empty()){
        ll cx = s.top().first, cy = s.top().second;
        s.pop();
        size++;
        for (int k = 0; k < 4; ++k){
            ll nx = cx + px[k];
            ll ny = cy + py[k];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && a[nx][ny] && !visited[nx][ny]){
                s.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    return size;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    ll maxs = INT_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!visited[i][j] && a[i][j]){
                maxs = max(maxs, dfs(i, j));
            }
        }
    }
    cout << maxs;
}
int main() {
    tassk();
    solve();
    return 0;
}