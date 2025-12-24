#include <bits/stdc++.h>
using namespace std;
#define task "repgame"
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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 4e18;
const ll MOD = 1e8;

ll n, m;
ll a[50005];
ll l[10], r[10];
ll p[10];
ll d[243], nd[243];

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
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> l[i] >> r[i];
    p[0] = 1;
    for(int i = 1; i <= m; ++i) p[i] = p[i-1] * 3;
    for(int i = 0; i < p[m]; ++i) d[i] = INF;
    d[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < p[m]; ++j) nd[j] = d[j];
        
        for(int b = 0; b < m; ++b) {
            int u = b + 1;
            ll pw = p[b], nxt = p[b+1];
            bool s = (i >= l[u] && i <= r[u]);
            bool k = (i <= r[u]);
            
            for(int low = 0; low < p[m]; low += nxt) {
                for(int j = 0; j < pw; ++j) {
                    int i0 = low + j;
                    int i1 = i0 + pw;
                    int i2 = i1 + pw;
                    
                    ll v0 = nd[i0], v1 = nd[i1], v2 = nd[i2];
                    ll n0 = v0, n1 = INF, n2 = min(v1, v2);
                    
                    if(s) n1 = min(n1, v0);
                    if(k) n1 = min(n1, v1);
                    
                    nd[i0] = n0; nd[i1] = n1; nd[i2] = n2;
                }
            }
        }

        for(int j = 0; j < p[m]; ++j) {
            if(nd[j] >= INF) {
                d[j] = INF;
                continue;
            }
            int f = m + 1, tmp = j;
            for(int b = 0; b < m; ++b) {
                if(tmp % 3 == 1) {
                    f = b + 1;
                    break;
                }
                tmp /= 3;
            }
            ll c = (f == m + 1 ? m : f - 1) * a[i];
            d[j] = nd[j] + c;
        }
    }

    ll ans = INF;
    for(int i = 0; i < p[m]; ++i) ans = min(ans, d[i]);
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}
