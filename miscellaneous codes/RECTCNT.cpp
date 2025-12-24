#include <bits/stdc++.h>
using namespace std;
#define task "RECTCNT"
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
const ll N = 5005;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

int n, q;
vector<string> g;
ll h[N][N];

ll calc() {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (g[i][j] == '1') h[i][j] = 0;
            else h[i][j] = (i == 0) ? 1 : h[i-1][j] + 1;
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        stack<pii> st;
        vll dp(n, 0);
        for (int j = 0; j < n; j++) {
            int k_prev = -1;
            while (!st.empty() && st.top().first >= h[i][j]) {
                st.pop();
            }
            if (!st.empty()) {
                k_prev = st.top().second;
            }
            
            dp[j] = (k_prev == -1 ? 0 : dp[k_prev]) + h[i][j] * (j - k_prev);
            ans += dp[j];
            st.push({h[i][j], j});
        }
    }
    return ans;
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

void solve() {
    cin >> n >> q;
    g.resize(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    cout << calc() << el;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        g[r][c] = (g[r][c] == '0' ? '1' : '0');
        cout << calc() << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}