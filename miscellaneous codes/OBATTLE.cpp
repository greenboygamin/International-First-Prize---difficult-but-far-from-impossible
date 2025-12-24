#include <bits/stdc++.h>
using namespace std;
#define task "OBATTLE"
#define ll long long int
#define pb push_back
#define el "\n"
#define pll pair<ll, ll>
const ll N = 1005;
ll n, m, a[N][N];
ll px[] = {0, 0, 1, -1, 1, -1, -1, 1};
ll py[] = {1, -1, 0, 0, 1, -1, 1, -1};
bool visited[N][N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}


ll dfs(ll x, ll y) {
    stack<pll> s;
    s.push({x, y});
    visited[x][y] = true;
    ll size = 0;
    while (!s.empty()) {
        ll cx = s.top().first, cy = s.top().second;
        s.pop();
        size++;
        for (int k = 0; k < 8; ++k) {
            ll nx = cx + px[k];
            ll ny = cy + py[k];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] && !visited[nx][ny]) {
                s.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return size;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
    ll dem = 0;
    ll maxs = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && a[i][j]) {
                dem++;
                maxs = max(maxs, dfs(i, j));
            }
        }
    }
    cout << dem << " " << maxs << el;
}

int main() {
    tassk();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
