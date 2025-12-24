#include <bits/stdc++.h>
using namespace std;
#define task "MAZE"
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
const ll M = 20;
const ll MOD = 2111992;
ll m, n, u, v, a[M][M];
bool visited[M][M];
ll px[] = {-1, 1, 0, 0};
ll py[] = {0, 0, -1, 1};
ll tracex[M][M];
ll tracey[M][M];
vector<pll> kq;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".INP", "r")) {
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
}

pair<pll, ll> bfs() {
    queue<pair<pll, ll>> q;
    q.push({{u, v}, 0});
    visited[u][v] = 1;
    tracex[u][v] = -1;
    tracey[u][v] = -1;

    while (!q.empty()) {
        ll x = q.front().first.first;
        ll y = q.front().first.second;
        ll ans = q.front().second;
        q.pop();

        if (x == 1 || x == m || y == 1 || y == n) {
            return {{x, y}, ans};
        }

        for (int i = 0; i < 4; i++) {
            ll cx = px[i] + x;
            ll cy = py[i] + y;
            if (1 <= cx && cx <= m && 1 <= cy && cy <= n && !visited[cx][cy] && !a[cx][cy]) {
                visited[cx][cy] = 1;
                q.push({{cx, cy}, ans + 1});
                tracex[cx][cy] = x;
                tracey[cx][cy] = y;
            }
        }
    }

    return {{0, 0}, -1};
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> u >> v;

    pair<pll, ll> result = bfs();
    if (result.second == -1) {
        cout << -1 << el;
    } else {
        cout << result.second << el;
        ll x = result.first.first;
        ll y = result.first.second;
        while (x > 0 && y > 0) {
            kq.pb({x, y});
            x = tracex[x][y];
            y = tracey[x][y];
        }
        reverse(kq.begin(), kq.end());
        for (auto i : kq) {
            if (i.first == u && i.second == v) continue;
            cout << i.first << " " << i.second << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
