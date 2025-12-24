#include <bits/stdc++.h>
using namespace std;

#define task "FRACSEQ"
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
const ll N = 2e6 + 7;
const ll M = 2e3 + 7;
const ll B = 505;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

bool isprime[N];
vi primes;

void sieve(){
    fill(isprime, isprime + N, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i < N; i++){
        if (isprime[i])
        for (int j = i * i; j < N; j += i){
            isprime[j] = 0;
        }
    }
    for (int i = 2; i < N; i++){
        if (isprime[i]) primes.pb(i);
    }
}

ll find_lpf(ll n) {
    ll lpf = 1;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        if (n % p == 0) {
            lpf = p;
            while (n % p == 0) {
                n /= p;
            }
        }
    }
    if (n > 1) {
        lpf = n;
    }
    return max(1LL, lpf); 
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

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x; 
        ll a = x + 1;
        ll b = x * x - x + 1;
        ll lpfA = find_lpf(a);
        ll lpfB = find_lpf(b);
        ll ans = max(lpfA, lpfB) - 1;
        cout << ans << el;
    }
}

int main() {
    tassk();
    sieve();
    solve();
    return 0;
}