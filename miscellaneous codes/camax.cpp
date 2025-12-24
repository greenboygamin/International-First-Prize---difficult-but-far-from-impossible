#include <bits/stdc++.h>
using namespace std;

#define task "camax"
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, t, k;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll sub(ll a, ll b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll powmod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void solve() {
    cin >> t >> n >> k;
    ll dem = 0, cnt = 0, ans = 0;
    for (ll i = 1; i <= n; i++){
        ll x; cin >> x;
        if (x <= k){
            dem++;
            cnt++;
        }
        else {
            ans = (ans + ((dem * (dem + 1)) / 2) % MOD) % MOD;
            dem = 0;
        }
    }
    ans = (ans + ((dem * (dem + 1)) / 2) % MOD) % MOD;
    cout << ans << " " << sub(powmod(2, cnt), 1); 
}


int main() {
    tassk();
    solve();
    return 0;
}   