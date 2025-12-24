#include <bits/stdc++.h>
using namespace std;

#define task "DIAGCOLOUR"
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

const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

ll n;
bool isprime[N];
vector<ll> primes;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void sieve(){
    fill(isprime, isprime + N, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i < N; i++){
        if (isprime[i]){
            for (int j = i * i; j < N; j += i){
                isprime[j] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++){
        if (isprime[i]) primes.pb(i);
    }
}

ll phi(ll x){
    ll res = x;
    for (ll p : primes){
        if (p * p > x) break;
        if (x % p == 0){
            while (x % p == 0) x /= p;
            res -= res / p;
        }
    }
    if (x > 1) res -= res / x;
    return res;
}

void solve() {
    cin >> n;
    ll c = 0, ans;
    for (ll g = 1; g * g <= n; g++){
        if (n % g == 0){
            ll m1 = n / g;
            c += phi(m1 + 1);
            if (g * g != n){
                ll m2 = g;
                c += phi(m2 + 1);
            }
        }
    }
    ans = (c + 1) / 2;
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}