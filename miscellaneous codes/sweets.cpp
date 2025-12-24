#include <bits/stdc++.h>
using namespace std;

#define task "sweets"
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
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = INT_MAX;
const ll MOD = 998244353;

ll n, a[N];
ll s = 0;
vector<vector<bool>> dp;

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

ll sub1and2(ll k, ll x, ll y, ll z){
    if (k > n){
        ll mx = max({x, y, z}), mn = min({x, y, z});
        return mx - mn;
    }
    return min({sub1and2(k + 1, x + a[k], y, z), sub1and2(k + 1, x, y + a[k], z), sub1and2(k + 1, x, y, z + a[k])});
}



void sub4(){
    dp.assign(s + 1, vector<bool>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        int v = a[i];
        auto tmp = dp;
        for (int x = 0; x <= s; x++){
            for (int y = 0; y <= s - x; y++){
                if (dp[x][y]){
                    if (x + v <= s) tmp[x + v][y] = 1;
                    if (y + v <= s) tmp[x][y + v] = 1;
                }
            }
        }
        dp = tmp;
    }
    int ans = INF;
    for (int x = 0; x <= s; x++){
        for (int y = 0; y <= s - x; y++){
            if (dp[x][y]) {
                int z = (s - x - y);
                int aa = max({x, y, z});
                int cc = min({x, y, z});
                ans = min(ans, aa - cc);
            }  
        }
    }
    cout << ans;
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    if (n <= 15) cout << sub1and2(1, 0, 0, 0);
    else sub4();
}

int main() {
    Task();
    Solve();
    return 0;
}
