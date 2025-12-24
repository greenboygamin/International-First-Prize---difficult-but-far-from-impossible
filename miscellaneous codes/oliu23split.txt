#include <bits/stdc++.h>
using namespace std;

#define task "d13jobshop"
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

int n, m, deg[N];
vector<int> adj[N];
vector<int> sto;
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int j; cin >> j;
            adj[j].pb(i);
            deg[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (deg[i] == 0) q.push(i);
    }
    int days = 0, done = 0;
    while (!q.empty()){
        int sz = q.size();
        int take = min(sz, m);
        sto.clear();
        for (int i = 0; i < take; i++){
            int u = q.front(); q.pop();
            sto.pb(u); done++;
        }
        for (int u : sto){
            for (int v : adj[u]){
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
        days++;
    }
    if (done == n) cout << days << el;
    else cout << -1 << el;
}

int main() {
    Task();
    Solve();
    return 0;
}