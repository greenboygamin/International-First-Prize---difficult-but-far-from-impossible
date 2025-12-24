#include <bits/stdc++.h>
using namespace std;

#define task "ISLANDS"
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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

int m, n;
vector<int> h[N];
int par[N], sz[N];
int px[] = {1, -1, 0, 0};
int py[] = {0, 0, -1, 1};
bool ok[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int idx(int x, int y){
    return x * n + y;
}

void init(int u){
    par[u] = u;
    sz[u] = 1;
}

int finds(int u){ 
    return (par[u] == u) ? u : (par[u] = finds(par[u]));
}

bool unites(int u, int v){
    u = finds(u); v = finds(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return true; 
}

bool check(int x, int y){
    return (0 <= x && x < m && 0 <= y && y < n);
}

void solve() {
    cin >> m >> n;
    int maxh = INT_MIN;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int height; cin >> height;
            h[height].pb(idx(i, j));
            maxh = max(maxh, height);
        }
    }
    int maxs = INT_MIN, dem = 0;
    for (int hei = maxh; hei >= 1; hei--){
        for (int id : h[hei]){
            ok[id] = 1;
            dem++;
            init(id);
        }
        for (int id : h[hei]){
            int x = id / n, y = id % n;
            //cout << x << " " << y << el;
            for (int k = 0; k < 4; k++){
                int nx = x + px[k];
                int ny = y + py[k];
                if (check(nx, ny) && ok[idx(nx, ny)]){
                    if (unites(id, idx(nx, ny))){
                        dem--;
                    }
                }
            }
            
        }
        
        maxs = max(maxs, dem);
        //cout << dem << el;
    }
    cout << maxs;
}

int main() {
    tassk(); 
    solve();
    return 0;
}   