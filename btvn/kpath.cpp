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

int n, k;
vi adj[N];
int dp[2 * M][2 * M][3];
ll tmp[2 * M][3];
int sz[2 * M];
int a[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void dfs(int u, int p){
    sz[u] = 1;
    for (int i = 0; i <= k; i++){
        dp[u][i][0] = dp[u][i][1] = dp[u][i][2] = -INF;
    }
    dp[u][0][0] = 0; dp[u][0][1] = a[u];
    if (k >= 1) dp[u][1][2] = a[u];
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        int nsz = min(k, sz[u] + sz[v]);
        for (int i = 0; i <= nsz; i++){
            tmp[i][0] = tmp[i][1] = tmp[i][2] = -INF;
        }
        for (int i = 0; i <= min(sz[u], k); i++){
            if (dp[u][i][0] == -INF && dp[u][i][1] == -INF && dp[u][i][2] == -INF) continue;
            for (int j = 0; j <= min(sz[v], k - i); j++){
                ll vvc = max(dp[v][j][0], dp[v][j][2]);
                ll vvo = dp[v][j][1];
                if (dp[u][i][0] > -INF && vvc > -INF) tmp[i + j][0] = max(tmp[i + j][0], dp[u][i][0] + vvc);
                if (dp[u][i][1] > - INF && vvc > -INF) tmp[i + j][1] = max(tmp[i + j][1], dp[u][i][1] + vvc);
                if (dp[u][i][0] > - INF && vvo > -INF) tmp[i + j][1] = max(tmp[i + j][1], dp[u][i][0] + vvo + a[u]);
                if (dp[u][i][2] > -INF && vvc > -INF) tmp[i + j][2] = max(tmp[i + j][2], dp[u][i][2] + vvc);
                if (i + j + 1 <= k && dp[u][i][1] > -INF && vvo > - INF) 
                    tmp[i + j + 1][2] = max(tmp[i + j + 1][2], dp[u][i][1] + vvo);
                
            }
        }
        sz[u] = nsz;
        for(int i = 0; i <= sz[u]; i++) {
            dp[u][i][0] = tmp[i][0];
            dp[u][i][1] = tmp[i][1];
            dp[u][i][2] = tmp[i][2];
        }
    }     
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, -1);
    ll ans = max(dp[1][k][0], dp[1][k][2]);
    cout << ans << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}

/*
 █████       █████  █████   █████████  █████   ████ █████ █████
▒▒███       ▒▒███  ▒▒███   ███▒▒▒▒▒███▒▒███   ███▒ ▒▒███ ▒▒███ 
 ▒███        ▒███   ▒███  ███     ▒▒▒  ▒███  ███    ▒███  ▒███ 
 ▒███        ▒███   ▒███ ▒███          ▒███████     ▒███  ▒███ 
 ▒███        ▒███   ▒███ ▒███          ▒███▒▒███    ▒███  ▒███ 
 ▒███      █ ▒███   ▒███ ▒▒███     ███ ▒███ ▒▒███   ▒███  ▒███ 
 ███████████ ▒▒████████   ▒▒█████████  █████ ▒▒████ █████ █████
▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒ 
*/