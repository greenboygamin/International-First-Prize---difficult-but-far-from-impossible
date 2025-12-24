#include <bits/stdc++.h>
using namespace std;

#define task "SMEX2"
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
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, a[M], dp[M][M], sum[M][M], mark[N];
vector<int> par, sz;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll add(ll a, ll b){
    a += b; if (a > MOD) a -= MOD; return a;
}

ll sub(ll a, ll b){
    a -= b; if (a <= 0) a += MOD; return a;
}

ll mul(ll a, ll b){
    return 1LL * a * b % MOD;
}

void init(){
    par.assign(M + 2, 0);
    sz.assign(M + 2, 1);
    for (int i = 1; i <= M; i++){
        par[i] = i;
    }
}

int finds(int u){
    return (par[u] == u) ? u : (par[u] = finds(par[u]));
}

void unites(int u, int v){
    u = finds(u); v = finds(v);
    if (u != v){
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = sum[0][0] = 1;
    //sum[j - 1][0] -> sum[j - 1][mex];
    for (int i = 1; i < M; i++) sum[0][i] = 1;
    for (int i = 1; i <= n; i++){
        init();
        for (int j = i; j > 0; j--){
            if (a[j] < M){
                if (a[j] != 0 && mark[a[j] - 1]) unites(a[j], a[j] - 1);
                if (a[j] != M - 1 && mark[a[j] + 1]) unites(a[j], a[j] + 1);
                mark[a[j]] = 1;
            }
            int mex = (mark[0] == 1 ? finds(0) + 1 : 0);
            dp[i][mex] = add(dp[i][mex], sum[j - 1][mex]);
        }
        for (int j = i; j > 0; j--){
            mark[a[j]] = 0;
        } 
        sum[i][0] = dp[i][0];  
        for (int j = 1; j < M; j++){
            sum[i][j] = add(sum[i][j - 1], dp[i][j]);
        }
    }    
    int ans = 0;
    for (int i = 0; i < M; i++) ans = add(ans, dp[n][i]);
    cout << ans;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
