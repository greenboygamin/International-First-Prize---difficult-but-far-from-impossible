#include <bits/stdc++.h>
using namespace std;

#define task "MAXVALUE"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1111 + 7;
const ll MOD = 1000009999;

ll n;
pll I[N];
ll D[N];

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

ll get_C(ll i, ll v) {
    ll l = I[i].first;
    ll r = I[i].second;
    if (v <= l) return 0;
    ll count = min(r, v - 1) - l + 1;
    return max(0LL, count);
}

void solve() {
    cin >> n;
    ll R_max = 0;
    set<ll> crit_points;
    crit_points.insert(1); 
    
    for (int i = 1; i <= n; ++i) {
        cin >> I[i].first >> I[i].second;
        D[i] = I[i].second - I[i].first + 1;
        R_max = max(R_max, I[i].second);
        
        crit_points.insert(I[i].first);
        crit_points.insert(I[i].second + 1);
    }
    
    vector<ll> V;
    for (ll v : crit_points) {
        if (v <= R_max + 1) {
            V.pb(v);
        }
    }
    
    ll Q = 1;
    for (int i = 1; i <= n; ++i) {
        Q = (Q * D[i]) % MOD;
    }
    
    ll numer_sum = 0;
    for (size_t j = 0; j < V.size() - 1; ++j) {
        ll V_j = V[j];
        ll V_j_plus_1 = V[j+1];
        
        ll P_C = 1;
        for (int i = 1; i <= n; ++i) {
            P_C = (P_C * get_C(i, V_j)) % MOD;
        }
        
        // Numerator contribution: (V_{j+1} - V_j) * (Q - P_C)
        ll L = (V_j_plus_1 - V_j) % MOD;
        ll term = (Q - P_C + MOD) % MOD;
        
        numer_sum = (numer_sum + L * term) % MOD;
    }
    
    // E[X] = numer_sum * Q^{-1}
    ll ans = (numer_sum * inv(Q)) % MOD;
    
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}