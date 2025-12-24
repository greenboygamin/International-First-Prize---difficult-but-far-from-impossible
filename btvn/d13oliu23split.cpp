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

ll n, k, w[N], pref[N];
ll ans;
vector<int> adj[N], gn[N];
ll minw = INT_MAX, sumw = 0;
ll sums[N], dp[N], cnt = 0;
vector<int> topo;

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

bool check(int x){  
    int cnt = 0;
    for (int u : topo){
        sums[u] = w[u];
        for (int v : gn[u]){
            sums[u] += sums[v];
        }
        if (sums[u] >= x){
            cnt++;
            sums[u] = 0;
            if (cnt >= k) return true;
        }
    }
    return cnt >= k;
}

void Solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        minw = min(minw, w[i]);
        sumw += w[i];
    }
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    stack<int> s;
    s.push(1);
    while (!s.empty()){
        int u = s.top(); s.pop();
        topo.push_back(u);
        for (int v : adj[u]){
            if (gn[v].size()) continue;
            gn[u].pb(v);
            s.push(v);
        }
    }
    reverse(topo.begin(), topo.end());
    ll l = minw, r = sumw;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    if (k == 1){
        cout << sumw << el;
        return;
    }
    cout << ans << el;
}

int main() {
    Task();
    Solve();
    return 0;
}
