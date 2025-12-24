#include <bits/stdc++.h>
using namespace std;

#define task "sweets"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = INT_MAX;
const ll MOD = 998244353;

int n, m, in[N], src, d[N];
vector<int> adj[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void dfs(int src){
    fill(d, d + N, INF);
    d[src] = 0;
    stack<int> s;
    s.push(src);
    while (!s.empty()){
        int u = s.top(); s.pop();
        for (int v : adj[u]){
            if (d[v] == INF){
                d[v] = d[u] + 1;
                s.push(v);
            }
        }
    }

}

void Solve() {
    cin >> n >> m;
    int total = (2 * n * m - m - n);
    for (int i = 1; i <= total; i++){
        int u, v; cin >> u >> v;
        in[u]++; in[v]++;
        adj[u].pb(v); adj[v].pb(u); 
    }
    cout << el << total << el;
    int deg2 = 4, deg3 = 2 * (n - 2) + 2 * (m - 2), deg4 = n * m - deg2 - deg3;
    int dem2 = 0, dem3 = 0, dem4 = 0;
    for (int i = 1; i <= n * m; i++){
        if (in[i] == 2) dem2++, src = i;
        else if (in[i] == 3) dem3++;
        else if (in[i] == 4) dem4++;
    }
    if (!(dem2 == deg2 && dem3 == deg3 && dem4 == deg4)){
        cout << "No" << el;
        return;
    }
    dfs(src);
    for (int i = 1; i <= n * m; i++) cout << i << " " << d[i] << el;

}

int main() {
    Task();
    Solve();
    return 0;
}
