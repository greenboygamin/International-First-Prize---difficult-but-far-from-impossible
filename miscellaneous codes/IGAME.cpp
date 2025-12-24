#include <bits/stdc++.h>
using namespace std;
#define task ""
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
const ll N = 2e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

int n, dp[N], cnt[N], ans[N];
vector<int> adj[N];

void dfs1(int u, int pre)
{
    dp[u] = 1;

    for (int v : adj[u])
    {
        if (v == pre)
            continue;

        dfs1(v, u);

        cnt[u] += (dp[v] == 1);
    }

    dp[u] = (cnt[u] == 0);
}

void dfs2(int u, int pre)
{
    ans[u] = (cnt[u] == 0);

    for (int v : adj[u])
    {
        if (v == pre)
            continue;
        int oldDpU = dp[u], oldDpV = dp[v], oldCntU = cnt[u], oldCntV = cnt[v];

        cnt[u] -= (oldDpV == 1), dp[u] = (cnt[u] == 0), cnt[v] += (dp[u] == 1), dp[v] = (cnt[v] == 0);

        dfs2(v, u);

        dp[u] = oldDpU, dp[v] = oldDpV, cnt[u] = oldCntU, cnt[v] = oldCntV;
    }
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n;

    for (int u, i = 2; i <= n; ++i)
        cin >> u, adj[i].push_back(u), adj[u].push_back(i);

    dfs1(1, 1), dfs2(1, 1);

    for (int i = 1; i <= n; ++i)
        if (ans[i])
            cout << i << el;

    return;
}

int main() {
    tassk();
    solve();
    return 0;
}