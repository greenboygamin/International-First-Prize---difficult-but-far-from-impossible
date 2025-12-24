#include <bits/stdc++.h>
using namespace std;

#define task "matgame"
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll N = 3e5 + 5;

int n, cnt = 0;
map<pii, int> id_map;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

struct DSU {
    vector<int> par; 
    vll val;
    
    void init(int n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        val.assign(n + 1, 0);
    }

    pll find(int i) {
        if (par[i] == i) return {i, 0};
        pll root = find(par[i]); 
        par[i] = root.fi;
        val[i] += root.se; 
        
        return {par[i], val[i]};
    }

    bool unite(int i, int j, ll w, ll &area) {
        pll root_i = find(i);
        pll root_j = find(j);
        int ri = root_i.fi;
        ll sum_i = root_i.se;
        int rj = root_j.fi;
        ll sum_j = root_j.se;

        if (ri != rj) {
            par[ri] = rj;
            val[ri] = sum_j - sum_i - w;
            return true;
        } else {
            ll cycleSum = sum_j - sum_i - w;
            area = abs(cycleSum) / 2; 
            return false;
        }
    }
} dsu;

int get_id(int x, int y) {
    if (id_map.find({x, y}) == id_map.end()) {
        id_map[{x, y}] = ++cnt;
    }
    return id_map[{x, y}];
}

void solve() {
    cin >> n;
    dsu.init(2 * n + 5);     
    for (int i = 1; i <= n; i++) {
        int x, y; char type;
        cin >> x >> y >> type;
        
        int u = get_id(x, y);
        int v;
        ll w = 0;
        
        if (type == 'x') {
            v = get_id(x + 1, y);
            w = -y;
        } else {
            v = get_id(x, y + 1);
            w = x;
        }
        
        ll area = 0;
        if (!dsu.unite(u, v, w, area)) cout << area << el;
        else cout << 0 << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}