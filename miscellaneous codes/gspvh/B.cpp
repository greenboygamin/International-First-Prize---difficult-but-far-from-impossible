#include <bits/stdc++.h>
using namespace std;

#define task "camax"
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
const ll MOD = 998244353;

int theta, n, k, a[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

ll add(ll a, ll b){
    return (a + b) % MOD;

}

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll calc(ll n){
    return (n * (n + 1)) / 2;
}

ll modpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void Solve(){
    cin >> theta >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll ans1 = 0, ans2 = 0;
    ll run = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= k){
            run++;
            ans2++;
        }
        else {
            ans1 = add(ans1, calc(run));
            run = 0;
        }
    }
    ans1 = add(ans1, calc(run));
    ans2 = modpow(2, ans2) - 1;
    cout << ans1 << " " << ans2 << el;
}

int main() {
    Task();
    Solve();
    return 0;
}

