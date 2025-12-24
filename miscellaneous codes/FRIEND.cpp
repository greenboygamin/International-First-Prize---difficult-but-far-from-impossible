#include <bits/stdc++.h>
using namespace std;

#define task "FRIEND"
#define ll long long int
#define el "\n"
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll INF = 1e9 + 7;

ll n, m, a, b, t, ha, sa, hb, sb, d[M][M], trace[M][M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void trloi(ll s, ll e) {
    vector<ll> ans;
    ll i = e;
    while (i != s) {
        ans.push_back(i);
        i = trace[s][i];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
    cout << el;
}

void solve() {
    cin >> n >> m;
    cin >> ha >> sa >> hb >> sb;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = (i == j) ? 0 : INF;
            trace[i][j] = i;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> t;
        d[a][b] = d[b][a] = t;
        trace[a][b] = a;
        trace[b][a] = b;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    trace[i][j] = trace[k][j];
                }
            }
        }
    }

    ll meet = -1;
    ll time = INF;

    for (int i = 1; i <= n; i++) {
        if (d[ha][i] == d[hb][i]) {
            if (d[ha][i] + d[i][sa] == d[ha][sa] && d[hb][i] + d[i][sb] == d[hb][sb] && d[ha][i] < time) {
                time = d[ha][i];
                meet = i;
            }
        }
    }

    if (meet != -1) {
        cout << "YES" << el;
        cout << d[ha][sa] << el;
        trloi(ha, sa);
        cout << d[hb][sb] << el;
        trloi(hb, sb);
        cout << meet << el << time << el;
    } else {
        cout << "NO" << el;
        cout << "YES" << el;
        cout << d[ha][sa] << el;
        trloi(ha, sa);
        cout << d[hb][sb] << el;
        trloi(hb, sb);
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
