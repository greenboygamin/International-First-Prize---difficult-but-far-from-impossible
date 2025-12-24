#include <bits/stdc++.h>
using namespace std;

#define task "d13jobshop"
#define el "\n"
#define pb push_back

typedef long long int ll;
typedef vector<int> vi;
const ll N = 1e6 + 7;
const ll INF = INT_MAX;

ll n, k, a[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void Solve() {
    if (!(cin >> n >> k)) return;
    vector<ll> vals(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vals[i] = a[i];
    }
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    // k là số lần được cắt cạnh
    ll cutsAllowed = k;
    if (cutsAllowed > n-1) cutsAllowed = n-1;

    // nén giá trị
    vector<ll> uniq;
    for (int i = 1; i <= n; ++i) uniq.pb(vals[i]);
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    int m = (int)uniq.size();
    vector<int> rk(n+1);
    for (int i = 1; i <= n; ++i)
        rk[i] = lower_bound(uniq.begin(), uniq.end(), vals[i]) - uniq.begin();

    const long long NEG = (long long)-4e18;

    function<vector<vector<long long>>(int,int)> dfs = [&](int u, int p) -> vector<vector<long long>> {
        int K = (int)cutsAllowed;
        vector<vector<long long>> dp(K+1, vector<long long>(m*m, NEG));
        int r = rk[u];
        dp[0][r*m + r] = 0;

        for (int v : g[u]) if (v != p) {
            auto child = dfs(v, u);
            vector<vector<long long>> ndp(K+1, vector<long long>(m*m, NEG));

            for (int cu = 0; cu <= K; ++cu) {
                for (int idxu = 0; idxu < m*m; ++idxu) {
                    long long val_u = dp[cu][idxu];
                    if (val_u == NEG) continue;
                    int minu = idxu / m;
                    int maxu = idxu % m;
                    for (int cv = 0; cv <= K - cu; ++cv) {
                        for (int idxv = 0; idxv < m*m; ++idxv) {
                            long long val_v = child[cv][idxv];
                            if (val_v == NEG) continue;
                            int minv = idxv / m;
                            int maxv = idxv % m;

                            // không cắt
                            int tot1 = cu + cv;
                            if (tot1 <= K) {
                                int newMin = min(minu, minv);
                                int newMax = max(maxu, maxv);
                                int idxNew = newMin * m + newMax;
                                long long nv = val_u + val_v;
                                if (nv > ndp[tot1][idxNew]) ndp[tot1][idxNew] = nv;
                            }

                            // cắt cạnh u-v
                            int tot2 = cu + cv + 1;
                            if (tot2 <= K) {
                                long long add = uniq[maxv] - uniq[minv];
                                int idxKeep = minu * m + maxu;
                                long long nv2 = val_u + val_v + add;
                                if (nv2 > ndp[tot2][idxKeep]) ndp[tot2][idxKeep] = nv2;
                            }
                        }
                    }
                }
            }

            dp.swap(ndp);
        }

        return dp;
    };

    auto dpRoot = dfs(1, 0);
    long long ans = NEG;
    int K = (int)cutsAllowed;
    for (int c = 0; c <= K; ++c) {
        for (int idx = 0; idx < m*m; ++idx) {
            long long closed = dpRoot[c][idx];
            if (closed == NEG) continue;
            int mn = idx / m;
            int mx = idx % m;
            long long tot = closed + (uniq[mx] - uniq[mn]);
            if (tot > ans) ans = tot;
        }
    }
    if (ans == NEG) ans = 0;
    cout << ans << el;
}

int main() {
    Task();
    Solve();
    return 0;
}
