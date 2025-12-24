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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

struct Edge {
    int v;
    ll w;
};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vll p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        vector<vector<Edge>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
        }
        vector<set<ll>> s(n + 1);
        queue<pair<int, ll>> q;
        
        if (p[1] >= 1) {
            s[1].insert(1);
            q.push({1, 1});
        }

        while (!q.empty()) {
            pair<int, ll> cur = q.front();
            q.pop();
            int u = cur.first;
            ll val = cur.second;

            for (auto& e : adj[u]) {
                ll nval = val * e.w;
                if (nval <= p[e.v]) {
                    if (s[e.v].find(nval) == s[e.v].end()) {
                        s[e.v].insert(nval);
                        q.push({e.v, nval});
                    }
                }
            }
        }

        if (s[n].empty()) cout << -1 << el;
        else cout << *s[n].rbegin() << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}