#include <bits/stdc++.h>
using namespace std;

#define task "BUYGOOD"
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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, m;
ll dp[N];
struct item{
    ll s, p, w;
};
vector<item> items(N);

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll add(ll a, ll b){
    a += b; if (a > MOD) a -= MOD; return a;
}

ll sub(ll a, ll b){
    a -= b; if (a <= 0) a += MOD; return a;
}

ll mul(ll a, ll b){
    return 1LL * a * b % MOD;
}

void solve() {
    cin >> n >> m;  
    for (int i = 1; i <= m; i++){
        cin >> items[i].s >> items[i].p >> items[i].w;
    }
    fill(dp, dp + N, INF);
    dp[0] = 0;
    for (int i = 1; i <= m; i++){
        ll si = items[i].s, wi = items[i].w, pi = items[i].p;
        for (ll j = n; j >= 0; j--){
            if (dp[j] == INF) continue;
            for (int k = 0; k <= min(n - j, si); k++){
                dp[j + k] = min(dp[j + k], dp[j] + wi + k * pi);
            }
        }
    }
    cout << dp[n] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
