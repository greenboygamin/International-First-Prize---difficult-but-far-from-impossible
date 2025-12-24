#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 5e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int isPal[M][M], dp[M][M], n, q;
string s;

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void Solve() {  
    cin >> s >> q;
    n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++){
        dp[i][i] = 1;
        isPal[i][i] = 1;
    }
    for (int len = 2; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            if (s[i] == s[j]){
                if (len == 2) isPal[i][j] = 1;
                else isPal[i][j] = isPal[i + 1][j - 1];
            }
        }
    }
    for (int len = 2; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + isPal[i][j];
            dp[i][j] = max(dp[i][j], 0);
        }
    }
    while (q--){
        int l, r; cin >> l >> r;
        cout << dp[l][r] << el;
    }
}


int main() {
    Task();
    Solve();
    return 0;
}   