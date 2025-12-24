#include <bits/stdc++.h>
using namespace std;

#define task "PIZZA"
#define ll long long int
#define ld long double
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue

const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
const ll INF = 1e9 + 7;

ll n, m, q, c[N], cake[N];
vector<vll> storecomp;
vector<ll> adj[N];
vector<bool> visited(N, 0);
ld result[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void bfs(ll u, vll &comp){
    visited[u] = true;
    comp.pb(u);
    for (auto v : adj[u]){
        if (!visited[v]){
            bfs(v, comp);
        }
    }
}

void findcomp(){
    ll dem = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dem++;
            vll comp;
            bfs(i, comp);
            storecomp.pb(comp);
        }
    }

    for (auto &arr : storecomp){
        ll price = 0;
        ll count = 0;
        for (auto i : arr){
            count++;
            if (cake[i]) {
                price += c[cake[i]];
            }
        }

        ld gia = (ld)price / (ld)count; 

        for (auto i : arr){
            result[i] = gia;
        }
    }

    cout << dem << el;
    for (int i = 1; i <= n; i++){
        cout << fixed << setprecision(8) << result[i] << el;
    }
}

void solve(){
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int i = 1; i <= q; i++){
        int z, x, k;
        cin >> z >> x >> k;
        if (z == 1){
            cake[x] = k;
        }
        else {
            adj[x].pb(k);
            adj[k].pb(x);
        }
    }
    findcomp();
}

int main() {
    tassk();
    solve();
    return 0;
}
