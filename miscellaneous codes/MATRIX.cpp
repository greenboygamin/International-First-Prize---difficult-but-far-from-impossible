#include <bits/stdc++.h>
using namespace std;
#define task "MATRIX"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef pair<int, int> pii;

const int N = 1005;
const ll INF = 1e18;

int n, q;
ll a[N][N];
ll best[N][N];
ll ans = 0;

void upd(int r, int c, queue<pii> &qu) {
    ll old = best[r][c];
    ll news = a[r][c];
    
    ll topp = (r > 1) ? best[r-1][c] : -INF;
    ll leftt = (c > 1) ? best[r][c-1] : -INF;
    
    if (r == 1 && c == 1) {
    } else {
        news += max(topp, leftt);
    }
    
    if (news != old) {
        ans = ans - old + news;
        best[r][c] = news;
                if (r + 1 <= n) qu.push({r + 1, c});
        if (c + 1 <= n) qu.push({r, c + 1});
    }
}

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
            
    best[1][1] = a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            ll mx = -INF;
            if (i > 1) mx = max(mx, best[i-1][j]);
            if (j > 1) mx = max(mx, best[i][j-1]);
            best[i][j] = a[i][j] + mx;
        }
    }
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans += best[i][j];
    while (q--) {
        int u, v, d;
        cin >> u >> v >> d;
        a[u][v] += d;
        queue<pii> qu;
        ll old = best[u][v];
        ll topp = (u > 1) ? best[u-1][v] : -INF;
        ll leftt = (v > 1) ? best[u][v-1] : -INF;
        ll news = a[u][v];
        if (u > 1 || v > 1) news += max(topp, leftt);
        if (news != old) {
            ans = ans - old + news;
            best[u][v] = news;
            if (u + 1 <= n) qu.push({u + 1, v});
            if (v + 1 <= n) qu.push({u, v + 1});
        }

        while (!qu.empty()) {
            pii top = qu.front(); qu.pop();
            upd(top.first, top.second, qu);
        }
        
        cout << ans << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}