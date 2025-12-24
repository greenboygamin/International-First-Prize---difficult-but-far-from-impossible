#include <bits/stdc++.h>
using namespace std;

#define task "BDC"
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
const ll M = 1e3 + 5;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

string type, s, t;
ll dp[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll get(char a, char b){
    return min(abs(a - b), 26 - abs(a - b));
}
void solve() {
    cin >> s >> t;
    //cout << s << " " << t << el;
    ll n = s.length();
    ll mint, mins;
    s = " " + s;
    t = " " + t;
    // dp[i][j]: min cost bien doi xau s va t thanh xau bucu tai vi tri s[i] va t[j]
    memset(dp, 63, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (char c = 'a'; c <= 'z'; c++){
                mins = get(s[i], c);
                mint = get(t[j], c);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + mint + mins);
            }
        }
    }
    string ans = ""; char cur; ll tmp = INF;
    ll i = n, j = n;
    while (i > 0 || j > 0){
        tmp = INF;
        for (char c = 'a'; c <= 'z'; ++c){
            if (j > 0) mint = get(t[j], c);
            if (i > 0) mins = get(s[i], c);
            if (mint + mins < tmp){
                tmp = mint + mins;
                cur = c;
            }
        }
        ans += cur;
        i--; j--;
        //else if (i > 0 && dp[i][j] == dp[i - 1][j] + get(s[i], cur)) i--;
        //else if (j > 0 && dp[i][j] == dp[i][j - 1] + get(t[j], cur)) j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << el;
}

int main() {
    tassk();
    while (cin >> type){
        if (type == "[CASE]") solve();
        else if (type == "[END]") break;
    }
    return 0;
}
