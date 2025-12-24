#include <bits/stdc++.h>
using namespace std;

#define task "DSF"
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
const ll N = 2e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

int n, m, par[N], sz[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    for (int i = 1; i <= 2 * n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int finds(int u){
    return (par[u] == u) ? u : (par[u] = finds(par[u]));
}

void unites(int u, int v){
    u = finds(u);
    v = finds(v);
    if (u != v){
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        int fu1 = finds(u), fv1 = finds(v), fu2 = finds(u + n), fv2 = finds(v + n);
        if (fu1 == fv1 || fu2 == fv2) cout << "N" << el;
        else {
            cout << "Y" << el;
            unites(u, v); unites(u + n, v + n);
        }
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}   