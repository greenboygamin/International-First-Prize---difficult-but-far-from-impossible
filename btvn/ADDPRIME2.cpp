#include <bits/stdc++.h>
using namespace std;

#define task "ADDPRIME"
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
const ll M = 1e4 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
bool isprime[N];
vll primes;
ll n, dp[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve() {
    cin >> n;
    fill(isprime, isprime + n + 1, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= n; i++){
        if (isprime[i]){
            for (int j = i * i; j <= n; j += i){
                isprime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (isprime[i]) primes.pb(i);
    }
    dp[0] = 1;
    for (int i = 0; i < primes.size(); ++i){
        for (int j = primes[i]; j <= n; ++j){
            if (dp[j - primes[i]] > 0) dp[j] = (dp[j] % MOD + dp[j - primes[i]] % MOD) % MOD;
        }
    }
    //for (int i = 1; i <= n; i++) cout << dp[i] << " " << isprime[i] << " " << i << el; 
    cout << dp[n] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
