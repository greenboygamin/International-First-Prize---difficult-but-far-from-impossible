#include <bits/stdc++.h>
using namespace std;

#define el "\n"
typedef long long ll;

const ll INF = 1e18;
const int MAXN = 105;
const int MAXK = 55;

int n, k;
vector<pair<int,int>> adj[MAXN]; // (neighbor, weight)
ll w[MAXN];                      // số người trong phòng
ll sumWeight[MAXN];              // tổng số người trong subtree

ll f[MAXN][MAXK]; // có điểm trốn trong subtree
ll g[MAXN][MAXK]; // không có điểm trốn trong subtree

// dfs tính subtree
void dfs(int u, int p) {
    sumWeight[u] = w[u];

    // Khởi tạo DP
    for (int i = 0; i <= k; i++) {
        f[u][i] = g[u][i] = INF;
    }
    f[u][1] = 0; // nếu chọn u làm điểm trốn
    g[u][0] = 0; // nếu không chọn trong subtree u
    for (auto [v, dist] : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        ll newF[MAXK], newG[MAXK];
        for (int i = 0; i <= k; i++) {
            newF[i] = newG[i] = INF;
        }

        // merge f[u] với con v
        for (int i = 0; i <= k; i++) {
            if (f[u][i] >= INF) continue;
            for (int j = 0; j <= k - i; j++) {
                // dùng f[v][j]
                if (f[v][j] < INF) {
                    newF[i+j] = min(newF[i+j], f[u][i] + f[v][j]);
                }
                // dùng g[v][j] -> tất cả người ở v phải đi lên u
                if (g[v][j] < INF) {
                    newF[i+j] = min(newF[i+j], f[u][i] + g[v][j] + sumWeight[v] * dist);
                }
            }
        }

        // merge g[u] với con v (u không có điểm trốn)
        for (int i = 0; i <= k; i++) {
            if (g[u][i] >= INF) continue;
            for (int j = 0; j <= k - i; j++) {
                // nếu v có điểm trốn thì vẫn ok
                if (f[v][j] < INF) {
                    newG[i+j] = min(newG[i+j], g[u][i] + f[v][j]);
                }
                // nếu v cũng không có điểm trốn -> vẫn chưa có, người v phải đi lên u
                if (g[v][j] < INF) {
                    newG[i+j] = min(newG[i+j], g[u][i] + g[v][j] + sumWeight[v] * dist);
                }
            }
        }

        // copy lại
        for (int i = 0; i <= k; i++) {
            f[u][i] = newF[i];
            g[u][i] = newG[i];
        }

        sumWeight[u] += sumWeight[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int u, d;
        cin >> w[i] >> u >> d;
        adj[u].push_back({i, d});
        adj[i].push_back({u, d});
    }
    
    dfs(0, -1);

    // kết quả = min f[0][x] với 1 <= x <= k
    ll ans = INF;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            cout << f[i][j] << " ";
        }
    }
    return 0;
}
