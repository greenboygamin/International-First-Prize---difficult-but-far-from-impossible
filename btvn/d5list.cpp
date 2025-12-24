#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

int n, w;
int s[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool check(int x){
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) dp[i] = 1e9;
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        int maxs = 0;
        for (int j = i; j >= max(1, i - x + 1); j--){
            maxs = max(maxs, s[j]);
            if (dp[j - 1] == 1e9) continue;
            int tmp = (j == 1) ? 0 : 1;
            int t = dp[j - 1] + tmp + maxs;
            dp[i] = min(dp[i], t);
        }
    }
    return dp[n] <= w;
}

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++){
        string ss; cin >> ss;
        s[i] = ss.length();
    }
    int l = 0, r = n, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    } 
    if (ans == -1) ans = n;
    cout << ans << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 