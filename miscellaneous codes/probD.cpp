#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll N = 1e5 + 5;
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, q;
int ok[N], cnt[N], maxc;
multiset<int> adj[N];
multiset<int> color[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}


void solve() {
    cin >> n >> q;
    int ans = 0;
    fill(ok, ok + N, 1);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= q; i++){
        char type;
        int u, v, c;
        cin >> type >> u >> v >> c;
        if (type == '+'){
            if (ok[c]) ans -= cnt[c];
            int c_u = adj[u].count(c);
            int c_v = adj[v].count(c);
            if (color[c].find(c_u) != color[c].end()) {
                color[c].erase(color[c].find(c_u));
            }
            color[c].insert(c_u + 1);
            if (color[c].find(c_v) != color[c].end()) {
                color[c].erase(color[c].find(c_v)); 
            }
            color[c].insert(c_v + 1);
            adj[u].insert(c); adj[v].insert(c);
            cnt[c]++;
            ok[c] = 0;
            if (color[c].empty() || (*color[c].rbegin() <= 1)) ok[c] = 1;
            if (ok[c]) ans += cnt[c]; 
            //for (auto id : color[c]) cout << id << " ";
            //cout << el << c_u << " " << c_v << el;; 
        }
        else {
            if (ok[c]) ans -= cnt[c];
            int c_u = adj[u].count(c);
            int c_v = adj[v].count(c);
            if (color[c].find(c_u) != color[c].end()) {
                color[c].erase(color[c].find(c_u));
            }
            if (c_u > 1) color[c].insert(c_u - 1);
            if (color[c].find(c_v) != color[c].end()) {
                color[c].erase(color[c].find(c_v));
            }
            if (c_v > 1) color[c].insert(c_v - 1);
            if (adj[u].find(c) != adj[u].end()) adj[u].erase(adj[u].find(c));
            if (adj[v].find(c) != adj[v].end()) adj[v].erase(adj[v].find(c));
            cnt[c]--;
            ok[c] = 0;
            if (color[c].empty() || (*color[c].rbegin() <= 1)) ok[c] = 1;
            if (ok[c]) ans += cnt[c]; 
        }
        maxc = max(maxc, c);
        //for (int j = 1; j <= maxc; j++) cout << ok[c] << " "; cout << el; 
        cout << ans << el;
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}
