#include <bits/stdc++.h>
using namespace std;
#define task "VIRUSS"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 2e18;

ll n, e, k;
pll a[5005];
ll dp[5005][5005];

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> e >> k;
        for(int i=1; i<=n; ++i) cin >> a[i].first >> a[i].second;

        for(int i=0; i<=n+1; ++i)
            for(int j=0; j<=k+1; ++j) dp[i][j] = INF;

        ll ans = 0;
        if(k == n) ans = e;

        for(int i=1; i<=n; ++i) {
            int skips = i - 1;
            if(skips > k) break;
            
            ll s = a[i].first;
            ll end = s + a[i].second;
            dp[i][skips] = end;
            
            ans = max(ans, min(e, s));
        }

        for(int i=1; i<=n; ++i) {
            for(int j=0; j<=k; ++j) {
                if(dp[i][j] == INF) continue;

                int rem = n - i;
                if(j + rem <= k) {
                    ll gap = 0;
                    if(dp[i][j] < e) gap = e - dp[i][j];
                    ans = max(ans, gap);
                }

                int limit = min((ll)n, i + 1 + (k - j));
                for(int next = i + 1; next <= limit; ++next) {
                    int cost = next - i - 1;
                    int nj = j + cost;
                    
                    ll s = max(a[next].first, dp[i][j]);
                    ll end = s + a[next].second;
                    
                    if(end < dp[next][nj]) {
                        dp[next][nj] = end;
                    }
                    
                    ll g_start = min(e, dp[i][j]);
                    ll g_end = min(e, s);
                    if(g_end > g_start) ans = max(ans, g_end - g_start);
                }
            }
        }
        cout << ans << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}