#include <bits/stdc++.h>
using namespace std;
#define task "SIEUTHI"
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
ll n, m, mins = 1e9, a[M][M], x, y, z;
vll adj[N];
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
            a[i][j] = 1e9;
            if (i == j) a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        a[x][y] = a[y][x] = z;
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
    ll sum, pos;
    for (int i = 1; i <= n; i++){
        sum = 0;
        for (int j = 1; j <= n; j++){
            sum += a[i][j];
        }
        if (sum < mins){
            mins = sum;
            pos = i;
        }
    }
    cout << pos << el << mins;
}

int main() {
    tassk();
    solve();
    return 0;
}