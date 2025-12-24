#include <bits/stdc++.h>
using namespace std;

#define task "eratosthene"
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
const ll N = 5e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 998244353;

ll l, r;
bool isprime[N];
vector<bool> res(N, 1);
vector<ll> primes;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void sieve(){
    for (int i = 2; i < N; i++) isprime[i] = 1;
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

void solve() {
    cin >> l >> r;
    sieve();
    for (auto p : primes){
        for (ll i = max(p * p, (l + p - 1) / p * p); i <= r; i += p){
            res[i - l] = 0;
        }
    }
    if (l == 1) res[0] = 0;
    int ans = 0;
    for (int i = 0; i <= r - l; i++) ans += res[i];
    cout << ans;
}


int main() {
    tassk();
    solve();
    return 0;
}   