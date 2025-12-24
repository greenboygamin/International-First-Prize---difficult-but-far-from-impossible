#include <bits/stdc++.h>
using namespace std;
#define task "cuuhoa"
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
ll n, m, x, y, w;
ll a[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) a[i][j] = 0;
            else a[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> w;
        a[x][y] = a[y][x] = w;
    }
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (a[i][k] < 1e9 && a[k][j] < 1e9){
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }
    ll tmp, maxs = 1e9, ans;
    for (int i = 1; i <= n; i++){
        tmp = 0;
        for (int j = 1; j <= n; j++){
            tmp = max(tmp, a[i][j]);
        }
        if (maxs > tmp){
            maxs = tmp;
            ans = i;
        }
    }
    cout << ans << el << maxs;
}

int main() {
    tassk();
    solve();
    return 0;
}