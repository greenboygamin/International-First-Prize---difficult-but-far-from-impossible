#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;
int n, d;
vector<int> a;
vector<vector<int>> adj;
vector<bool> imp;
vector<vector<ll>> dp;  // dp[u][e], e = 0..d+1

void dfs(int u, int p) {
    // init
    dp[u].assign(d+2, INF);
    dp[u][0] = a[u];
    for(int e = 1; e <= d+1; ++e)
        dp[u][e] = imp[u] ? INF : 0;

    // merge children
    for(int v: adj[u]) if(v!=p) {
        dfs(v, u);
        vector<ll> tmp(d+2, INF);
        for(int e1 = 0; e1 <= d+1; ++e1) if(dp[u][e1] < INF) {
            for(int e2 = 0; e2 <= d+1; ++e2) if(dp[v][e2] < INF) {
                int ev = min(e1+1, d+1);         // v nhìn lên u
                int e_new = min(e1, ev);        // khoảng cách gần nhất
                tmp[e_new] = min(tmp[e_new],
                                 dp[u][e1] + dp[v][e2]);
            }
        }
        dp[u].swap(tmp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int m; cin >> m;
    imp.assign(n, false);
    while(m--){
        int x; cin >> x;
        imp[x-1] = true;
    }

    adj.assign(n, {});
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dp.assign(n, vector<ll>());
    dfs(0, -1);
    ll ans = dp[0][d+1];
    cout << ans << "\n";
    return 0;
}
