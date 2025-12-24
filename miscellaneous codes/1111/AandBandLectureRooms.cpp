#include <bits/stdc++.h>
using namespace std;

#define task "BAI4"
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

const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 4e18;


const ll MOD = 1e9 + 7;
const ll INV2 = 500000004; 

ll v, l, r, vmod, lmod, rmod, res, sum, nmod;

void tassk() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

ll calc(ll n) {
    res = (n + 1) % MOD;
    sum = 0;
    l = 1;
    nmod = n % MOD;
    while (l <= n) {
        v = n / l;
        r = n / v;
        vmod = v % MOD;
        lmod = l % MOD;
        rmod = r % MOD;
        ll c1 = (vmod * (nmod + 1)) % MOD;
        ll c2 = (vmod * (vmod + 1)) % MOD * INV2 % MOD;
        ll cnt = (rmod - lmod + 1 + MOD) % MOD;
        ll ki = c1 * cnt % MOD;
        ll sum_d = ((rmod + lmod) % MOD) * cnt % MOD * INV2 % MOD;
        ll quan = c2 * sum_d % MOD;
        sum = (sum + ki - quan + MOD) % MOD;
        l = r + 1;
    }
    return (res + sum) % MOD;
}

void solve() {
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        cout << calc(n) << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
