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
const ll N = 50;
const ll M = 1e3 + 7;
const ll B = 1e6;
const ll INF = INT_MAX;
const ll MOD = 1e9 + 7;

int n, m, k;
ll fact[N], invFact[N], dp[N][N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll pow_mod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
    invFact[N - 1] = pow_mod(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) invFact[i] = mul(invFact[i + 1], i + 1);
}

ll C(ll n, ll k){
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(invFact[k], invFact[n - k]));
}

void Solve() {
    cin >> n >> m >> k;
    init();
    for (int j = 0; j <= n; j++) dp[1][j] = C(n, j);
    //dp[i][j]: i column, last column j bits is 1
    for (int i = 2; i <= m; i++){
        for (int j = 0; j <= n; j++){
            for (int x = 0; x <= min(j, k); x++){
                int cnt0 = j - x;
                for (int y = 0; y <= n - j; y++){
                    dp[i][cnt0 + y] = add(dp[i][cnt0 + y], mul(dp[i - 1][j], mul(C(j, x), C(n - j, y))));
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans = add(ans, dp[m][i]);
    cout << ans;
}


int main() {
    Task();
    Solve();
    return 0;
}   