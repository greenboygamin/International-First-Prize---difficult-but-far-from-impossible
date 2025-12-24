#include <bits/stdc++.h>
using namespace std;
#define task "Dauloang"
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
ll n, m, a[M][M];
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
ll dfs(int x, int y){
    stack<pii> s;
    s.push({x, y});
    visited[x][y] = 1;
    ll size = 0;
    while (!s.empty()){
        ll cx = s.top().first, cy = s.top().second;
        s.pop();
        size++;
        for (int k = 0; k < 4; k++){
            int nx = cx + px[k];
            int ny = cy + py[k];
            if (1 <= nx && 1 <= ny && nx <= n && ny <= m && !visited[nx][ny] && a[nx][ny]){
                visited[nx][ny] = 1;
                s.push({nx, ny});
            }
        }
    }
    return size;
}
void solve() {
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    vll ans;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (!visited[i][j] && a[i][j]){
                ll dem = dfs(i, j);
                ans.pb(dem);
            }
        }
    }
    cout << ans.size() << el;
    sort(ans.begin(), ans.end());
    if (!ans.empty()){
        map<ll, ll> count;
        for (auto i : ans){
            count[i]++;
        }
        for (auto z : count){
            cout << z.first << " " << z.second << el;
        }
    }
}
int main() {
    tassk();
    solve();
    return 0;
}