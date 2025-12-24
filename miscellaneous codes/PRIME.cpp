#include <bits/stdc++.h>
using namespace std;

#define task "SMEX2"
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

int isprime[2 * N];
vector<int> primes;


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

void sieve(){
    for (int i = 2; i < 2 * N; i++) isprime[i] = 1;
    for (int i = 2; i * i < 2 * N; i++){
        if (isprime[i]){
            for (int j = i * i; j < 2 * N; j += i){
                isprime[j] = 0;
            }
        }
    }

}

void solve() {
    ll n; cin >> n;
    int dem = 0;
    for (ll i = n; i <= 2 * n; i++) dem += isprime[i];
    cout << dem << el;
}

int main() {
    tassk();
    sieve();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
