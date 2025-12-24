#include <bits/stdc++.h>
using namespace std;

#define task "CACHE"
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
const ll N = 1e3 + 5;
const ll M = 2e4 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

int n, k;
int a[M];
dqll t[M]; 
vector<int> s[N];
int p[M];
ll ans = 0;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int gw(int u) {
    if (t[u].empty()) return INF;
    return t[u].front();
}

void rec(int i, int u);

void req(int i, int u) {
    if (p[u] == i) return;
    if (s[i].size() == 2) {
        int v = -1, mx = -1;
        for (int x : s[i]) {
            int w = gw(x);
            if (w > mx) { mx = w; v = x; }
        }
        rec(i - 1, v);
    }
    req(i - 1, u);
    if (i - 1 > 0) {
        for (int j = 0; j < s[i - 1].size(); j++) {
            if (s[i - 1][j] == u) {
                s[i - 1].erase(s[i - 1].begin() + j);
                break;
            }
        }
    }
    s[i].pb(u);
    p[u] = i;
    ans++;
}

void rec(int i, int u) {
    if (i > 0 && s[i].size() == 2) {
        int v = -1, mx = -1;
        for (int x : s[i]) {
            int w = gw(x);
            if (w > mx) { mx = w; v = x; }
        }
        rec(i - 1, v);
    }
    int cur = p[u];
    if (cur > 0) {
        for (int j = 0; j < s[cur].size(); j++) {
            if (s[cur][j] == u) {
                s[cur].erase(s[cur].begin() + j);
                break;
            }
        }
    }
    if (i > 0) s[i].pb(u);
    p[u] = i;
    ans++;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        t[a[i]].pb(i);
    }
    
    for (int i = 1; i <= k; i++) {
        int u = a[i];
        t[u].pop_front(); 
        req(n, u);
    }

    for (int i = n; i >= 1; i--) {
        while (!s[i].empty()) {
            rec(i - 1, s[i].back());
        }
    }
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}