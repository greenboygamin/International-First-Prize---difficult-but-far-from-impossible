#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, MOD = 666013;

int n, dp[N], subtree_size[N];
int fact[N], invFact[N];
vector<int> nxt[N];

int modInverse(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

void precalc(int n) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    }
    invFact[n] = modInverse(fact[n], MOD);
    for (int i = n - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % MOD;
    }
}

int calc(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * 1LL * invFact[k] % MOD * invFact[n - k] % MOD;
}

void dfs(int u, int parent) {
    subtree_size[u] = 1;
    dp[u] = 1;
    for (auto v : nxt[u]) {
        if (v == parent) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
        dp[u] = dp[u] * 1LL * dp[v] % MOD;
    }
    int ways = fact[subtree_size[u] - 1];
    for (auto v : nxt[u]) {
        if (v == parent) continue;
        ways = ways * 1LL * invFact[subtree_size[v]] % MOD;
    }
    dp[u] = dp[u] * 1LL * ways % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("BAI3.inp", "r")) {
        freopen("BAI3.inp", "r", stdin);
        freopen("BAI3.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }

    precalc(n);
    dfs(1, 0);
    cout << dp[1];

    return 0;
}
