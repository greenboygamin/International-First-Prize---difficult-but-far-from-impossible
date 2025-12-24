#include <bits/stdc++.h>
using namespace std;
#define task "plan"
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
const ll INF = 2e9;
const ll MOD = 1e9;

int m, A, B;
int a[15], b[15];
int dp[55][55], ndp[55][55];
int sa[1025], sb[1025];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> m >> A >> B;
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    int lm = (1 << m);
    for (int i = 0; i < lm; i++) {
        int ta = 0, tb = 0;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                ta += a[j];
                tb += b[j];
            }
        }
        sa[i] = ta;
        sb[i] = tb;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int k = 0; k <= 35; k++) {
        memset(ndp, 0, sizeof(ndp));
        int bA = (k > 30) ? 0 : ((A >> k) & 1);
        int bB = (k > 30) ? 0 : ((B >> k) & 1);
        for (int i = 0; i < lm; i++) {
            int va = sa[i];
            int vb = sb[i];
            for (int ca = 0; ca <= 50; ca++) {
                for (int cb = 0; cb <= 50; cb++) {
                    if (!dp[ca][cb]) continue;      
                    if ((ca + va) % 2 != bA) continue;
                    if ((cb + vb) % 2 != bB) continue;
                    int nca = (ca + va) >> 1;
                    int ncb = (cb + vb) >> 1;
                    ndp[nca][ncb] = (ndp[nca][ncb] + dp[ca][cb]);
                    if (ndp[nca][ncb] >= MOD) ndp[nca][ncb] -= MOD;
                }
            }
        }
        for (int ca = 0; ca <= 50; ca++)
            for (int cb = 0; cb <= 50; cb++)
                dp[ca][cb] = ndp[ca][cb];
    }
    cout << dp[0][0] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}