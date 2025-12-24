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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

ll n, m, a[N];
ll dp[M][M];
ll pref[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll calc(int l, int r){
    if (l > r) return 0;
    return (pref[r] - pref[l - 1]) * (r - l + 1);
}

void dnc(int k, int l, int r, int ll, int rr){
    if (l > r) return;
    int mid = (l + r) / 2;
    dp[mid][k] = INF;
    int idx = -1;
    int lim = min(mid - 1, rr);
    for (int i = ll; i <= lim; i++){
        if (dp[mid][k] > dp[i][k - 1] + calc(i + 1, mid)){
            dp[mid][k] = dp[i][k - 1] + calc(i + 1, mid);
            idx = i;
        }
    }
    if (idx != -1){
        dnc(k, l, mid - 1, ll, idx);
        dnc(k, mid + 1, r, idx, rr);
    }
}

void solve() {
    cin >> n >> m;
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) dp[i][1] = calc(1, i);
    for (int j = 2; j <= m; j++){
        dnc(j, 1, n, 0, n);
    }
    cout << dp[n][m];
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 