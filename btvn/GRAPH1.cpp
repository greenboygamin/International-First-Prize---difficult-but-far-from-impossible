#include <bits/stdc++.h>
using namespace std;

#define task "GRAPH"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;
int n, m;
vll adj[N];
bool visited[N], a[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void bfs(int u){
    cout << u << " ";
    visited[u] = 1;
    for (int j = 1; j <= n; j++){
        if (!visited[j] && a[u][j]){
            bfs(j);
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) a[i][i] = 1;
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][k] && a[k][j]) a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            bfs(i);
            cout << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}