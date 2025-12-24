#include <bits/stdc++.h>
using namespace std;

#define task "QFRIEND"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

ll n, m, q, s;
vi adj[N];
int kn[N];
bool vis[N];
int tmr;
ll last = 0;

int A[N];
ll ans[N];
vi bit;

struct Event {
    int x, y, type, idx;
};
vector<Event> events;

bool cmp(const Event& a, const Event& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.type < b.type;
}

void upd(int y, int val) {
    y++; 
    for (; y <= n + 1; y += y & (-y))
        bit[y] += val;
}

int qry(int y) {
    y++;
    int sum = 0;
    for (; y > 0; y -= y & (-y))
        sum += bit[y];
    return sum;
}

void dfs(int u){
    vis[u] = 1;
    kn[u] = tmr++;
    for (int v : adj[u]){
        if (vis[v]) continue;
        dfs(v);
    }
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m >> q >> s;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    
    tmr = 1;
    for (int i = 1; i <= n; i++){
        if (!vis[i]) dfs(i);
        A[i] = 0;
    }

    if (s == 1) {
        while (q--){
            ll x, y; cin >> x >> y;
            ll dem = 0;
            ll l = (x + s * last - 1) % n + 1;
            ll r = (y + s * last - 1) % n + 1;
            if (l > r) swap(l, r);
            for (int p = l; p <= r; p++){
                bool ok = 1;
                for (int v : adj[p]){
                    if (l <= v && v <= r){
                        if (kn[v] < kn[p]) {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) dem++;
            }
            cout << dem << el;
            last = dem;
        }
    } else {
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                if (kn[v] < kn[u]) {
                    A[u] = max(A[u], v);
                }
            }
            events.pb({u, A[u], 0}); 
        }

        for (int i = 0; i < q; i++) {
            ll x, y; cin >> x >> y;
            ll l = (x - 1) % n + 1;
            ll r = (y - 1) % n + 1;
            if (l > r) swap(l, r);
            
            events.pb({r, (int)l - 1, 2, i});     
            events.pb({(int)l - 1, (int)l - 1, 1, i}); 
        }
        
        sort(events.begin(), events.end(), cmp);

        bit.assign(n + 2, 0);

        for (const auto& e : events) {
            if (e.type == 0) { 
                upd(e.y, 1);
            } else if (e.type == 1) { 
                ans[e.idx] -= qry(e.y);
            } else { 
                ans[e.idx] += qry(e.y);
            }
        }
        
        for(int i = 0; i < q; i++) {
            cout << ans[i] << el;
        }
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}