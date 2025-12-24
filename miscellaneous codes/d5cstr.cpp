#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
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

string s, t;
int dp[M][M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> s >> t;
    if (s.length() > t.length()) swap(s, t);
    int m = s.length(), n = t.length();
    s = " " + s; t = " " + t;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i] == t[j]){
                dp[i][j] =max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    int k = dp[m][n], res = 1;
    if (k >= (n + 1) / 2 && k >= (m + 1) / 2){
        cout << 1 << el;
        return;
    }
    while (n - (n / 2) > k){
        k += m;
        m += m;
        res++;
    }
    cout << res << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 