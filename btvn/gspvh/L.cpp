#include <bits/stdc++.h>
using namespace std;

#define task "tree-edge-color-queries"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
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

int theta, n, q, c[N], u[N], v[N], e[N];
map<int, int> col[N];
vi adj[N];

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
    cin >> theta >> n;
    int res = 0;
    for (int i = 1; i < n; i++){
        cin >> u[i] >> v[i] >> c[i];
        adj[u[i]].pb(i); adj[v[i]].pb(i);
        e[c[i]]++;
        if (col[u[i]][c[i]]++ == 0) res++;
        if (col[v[i]][c[i]]++ == 0) res++;   
    }
    res -= n - 1;
    cout << res << " ";
    cin >> q;
    for (int i = 1; i <= q; i++){
        int edge, color; cin >> edge >> color;
        e[c[edge]]--;
        e[color]++;
        if (--col[u[edge]][c[edge]] == 0) res--;
        if (--col[v[edge]][c[edge]] == 0) res--;
        if (col[u[edge]][color]++ == 0) res++;
        if (col[v[edge]][color]++ == 0) res++;
        c[edge] = color;
        cout << res << " ";
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
