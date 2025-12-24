#include <bits/stdc++.h>
using namespace std;

#define task "DIVGOLD"
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
const ll MOD = 1e6;
bool isprime[N];
ll n, dp[N], v[N], tv[N];

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
    ll s = 0;
    for (int i = 1; i <= n; i++) cin >> v[i], s += v[i];
    dp[0] = 1; tv[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = s / 2; j >= v[i]; j--){
            if (dp[j - v[i]]){
                dp[j] = 1;
                tv[j] = (tv[j] % MOD + tv[j - v[i]] % MOD) % MOD;
            }
        }
    }
    ll i = s / 2;
    while (!dp[i]) i--;
    cout << s - i * 2 << el;
    cout << tv[i];
}

int main() {
    tassk();
    solve();
    return 0;
}
