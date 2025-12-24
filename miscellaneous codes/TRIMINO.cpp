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
const ll N = 105;
const ll MOD = 998244353;

int n, m;
vector<string> g;
map<pii, vector<pair<pii, pii>>> ok;
map<pii, pii> par;

pii find(pii s) {
    if (par.find(s) == par.end() || par[s] == s)
        return par[s] = s;
    return par[s] = find(par[s]);
}
void unite(pii a, pii b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        par[b] = a;
    }
}

bool check(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

pii quay_tay(int r, int c) {
    return {r, c};
}

ll dem(const vector<pii>& comp, int k, set<pii>& used) {
    if (k == comp.size()) {
        return 1;
    }

    pii s = comp[k];
    ll ans = 0;
    for (auto shape : ok[s]) {
        pii tay1 = shape.first;
        pii tay2 = shape.second;
        if (used.count(tay1) || used.count(tay2)) {
            continue;
        }
        used.insert(tay1);
        used.insert(tay2);
        ans = (ans + dem(comp, k + 1, used)) % MOD;
        used.erase(tay1);
        used.erase(tay2);
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    vector<pii> quan;
    ok.clear();
    par.clear();
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '*') {
                quan.pb({i, j});
            }
        }
    }
    map<pii, vector<pii>> tay;
    for (pii s : quan) {
        int r = s.first;
        int c = s.second;
        vector<pair<pii, pii>> shapes;
        pii tay_u = quay_tay(r - 1, c);
        pii tay_d = quay_tay(r + 1, c);
        pii tay_l = quay_tay(r, c - 1);
        pii tay_r = quay_tay(r, c + 1);
        if (check(r - 1, c) && g[r - 1][c] == '.' && check(r, c - 1) && g[r][c - 1] == '.') shapes.pb({tay_u, tay_l});
        if (check(r - 1, c) && g[r - 1][c] == '.' && check(r, c + 1) && g[r][c + 1] == '.') shapes.pb({tay_u, tay_r});
        if (check(r + 1, c) && g[r + 1][c] == '.' && check(r, c - 1) && g[r][c - 1] == '.') shapes.pb({tay_d, tay_l});
        if (check(r + 1, c) && g[r + 1][c] == '.' && check(r, c + 1) && g[r][c + 1] == '.') shapes.pb({tay_d, tay_r});

        if (shapes.empty() && !quan.empty()) {
            cout << 0 << el;
            return;
        }
        ok[s] = shapes;
        for (auto shape : shapes) {
            tay[shape.first].pb(s);
            tay[shape.second].pb(s);
        }
    }

    for (pii s : quan) {
        par[s] = s;
    }
    
    for (auto const& pair : tay) {
        const vector<pii>& ki = pair.second;
        for (int i = 1; i < ki.size(); i++) {
            unite(ki[0], ki[i]);
        }
    }

    map<pii, vector<pii>> comps;
    for (pii s : quan) {
        comps[find(s)].pb(s);
    }

    ll ans = 1;
    for (auto const& pair : comps) {
        const vector<pii>& comp = pair.second;
        set<pii> used;
        ll cmp = dem(comp, 0, used);
        if (cmp == 0) {
            ans = 0;
            break;
        }
        ans = (ans * cmp) % MOD;
    }

    cout << ans << el;
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int main() {
    tassk();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
