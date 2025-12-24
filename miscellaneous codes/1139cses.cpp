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
typedef long double ld;
const ll N = 3e6 + 5;
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, q, a[N];
vector<map<int, int>> color(N);
vector<int> sz(N), par(N);
vector<int> res(N);

    void init(int v){
        color[v][a[v]] = 1;
        sz[v] = 1;
        par[v] = v;
    }

    int finds(int u){
        return (par[u] == u) ? u : (par[u] = finds(par[u]));
    }

    void merges(int u, int v){
        u = finds(u); v = finds(v);
        if (u != v){
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
            for (auto c : color[v]) color[u][c.first] += c.second;
        }
    }

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    int maxc = INT_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        init(i);
        maxc = max(maxc, a[i]);
    } 
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        merges(u, v);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= maxc; j++){
            res[i] += (color[i][j] > 0);
            cout << i << " " << j << " " << color[i][j] << el;
        }
    }
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}

int main() {
    tassk(); 
    solve();
    return 0;
}
