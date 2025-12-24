#include <bits/stdc++.h>
using namespace std;
#define task "ditmephu"
#define ll long long int
#define el "\n"
const ll MOD = 1e9+7;
ll calc(ll base, ll exp, ll mod) {
    ll res = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void precom(vector<ll>& fax, vector<ll>& inv, ll maxs, ll mod) {
    fax[0] = 1;
    for (ll i = 1; i <= maxs; ++i) {
        fax[i] = (fax[i - 1] * i) % mod;
    }

    inv[maxs] = calc(fax[maxs], mod - 2, mod);
    for (ll i = maxs - 1; i >= 0; --i) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}
ll sum(ll x, ll n, ll mod) {
    vector<ll> fax(n + 2), inv(n + 2);
    precom(fax, inv, n + 1, mod);
    vector<ll> ben(n + 1);
    ben[0] = 1;
    for (ll m = 1; m <= n; ++m) {
        ben[m] = 0;
        for (ll k = 0; k < m; ++k) {
            ben[m] = (ben[m] + ben[k] * inv[m + 1 - k] % mod * inv[k] % mod * fax[m] % mod) % mod;
        }
        ben[m] = (mod - ben[m]) % mod;
    }
    ll sum = 0;
    for (ll k = 0; k <= n; ++k) {
        ll term = ben[k] * inv[n + 1 - k] % mod * inv[k] % mod;
        term = term * calc(x, n + 1 - k, mod) % mod;
        sum = (sum + term) % mod;
    }
    sum = sum * calc(n + 1, mod - 2, mod) % mod;
    return sum;
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    ll x, n;
    cin >> x >> n;
    ll res = sum(x, n, MOD);
    cout << res << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
