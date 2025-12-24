#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

int n;  
vi adj_geo[N];
vpii adj[N];
int cnt = 0;
map<pii, int> diag;
map<vi, int> tmap;
int dp[N][2];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool tknp(const vi &arr, int val){
    int l = 0, r = arr.size() - 1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (arr[mid] == val) return true;
        if (arr[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

vi get_com(int u, int v){
    vi res;
    if (adj_geo[u].size() > adj_geo[v].size()) swap(u, v);
    for (int x : adj_geo[u]){
        if (tknp(adj_geo[v], x)) res.pb(x);
    }
    return res;
}

void build(){
    for (int i = 1; i <= n; i++) sort(adj_geo[i].begin(), adj_geo[i].end());
    vpii edges;
    for (int i = 1; i <= n; i++) edges.pb({i, (i % n) + 1});
    for (auto const &val : diag) edges.pb(val.fi);
    for (auto e : edges){
        vi cm = get_com(e.fi, e.se);
        for (int w : cm){
            vi tz = {e.fi, e.se, w};
            sort(tz.begin(), tz.end());
            if (tmap.find(tz) == tmap.end()) tmap[tz] = ++cnt;
        }
    }
    for (auto const &val : diag){
        int u = val.fi.fi;
        int v = val.fi.se;
        int id = val.se;
        vi cm = get_com(u, v);
        if (cm.size() >= 2){
            vi t1 = {u, v, cm[0]}; sort(t1.begin(), t1.end());
            vi t2 = {u, v, cm[1]}; sort(t2.begin(), t2.end());
            int i1 = tmap[t1];
            int i2 = tmap[t2];
            adj[i1].pb({i2, id});
            adj[i2].pb({i1, id});
        }
    }
}

void dfs(int u, int p){
    int sum = 0;
    bool leaf = 0, ok = 0;
    int mins = 1e9;
    for (auto &e : adj[u]){
        int v = e.fi;
        if (v == p) continue;
        leaf = 0;
        dfs(v, u);
        if (dp[v][0] <= dp[v][1]){
            sum += dp[v][0];
            ok = 1;
        }
        else sum += dp[v][1];
        mins = min(mins, dp[v][0] - dp[v][1]);
    }
    dp[u][0] = sum + 1;
    if (leaf) dp[u][1] = INF;
    else {
        dp[u][1] = sum;
        if (!ok) dp[u][1] += mins;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        int nxt = (i % n) + 1;
        adj_geo[i].pb(nxt);
        adj_geo[nxt].pb(i);
    }
    for (int k = 1; k <= n - 3; k++){
        int u, v; cin >> u >> v;
        adj_geo[u].pb(v); adj_geo[v].pb(u);
        if (u > v) swap(u, v);
        diag[{u, v}] = k;
    }
    build();
    if (cnt <= 1) cout << 0 << el;
    else {
        dfs(1, -1);
        cout << dp[1][1] << el;
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 