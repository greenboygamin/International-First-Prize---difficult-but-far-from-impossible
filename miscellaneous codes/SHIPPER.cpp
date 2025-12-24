#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define el "\n"
#define task "shipper"
typedef long long int ll;
typedef vector<ll> vll;

const int M = 1000 + 7;
int n, m, cost[M][M], x[M];
int mins = INT_MAX;
bool visited[M];
vll ans;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void np(int i, int temp){
    for (int j = 1; j <= n; j++){
        if (cost[x[i - 1]][j] > 0 && !visited[j]){
            x[i] = j; 
            if (i < n){
                visited[j] = 1;
                np(i + 1, temp + cost[x[i - 1]][j]);
                visited[j] = 0;
            }
            else {
                if (cost[x[i - 1]][j] > 0){
                    temp += cost[x[i - 1]][j] + cost[j][x[1]];
                    if (mins > temp){
                        mins = temp;
                        ans.clear();
                        for (int z = 1; z <= n; z++) ans.pb(x[z]);
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u][v] = c;
        cost[v][u] = c;
    }
    x[1] = 1;
    visited[1] = 1;
    np(2, 0);
    cout << mins << el;
    for (auto i : ans) cout << i << " "; cout << 1;
}

int main() {
    tassk();
    solve();
    return 0;
}
