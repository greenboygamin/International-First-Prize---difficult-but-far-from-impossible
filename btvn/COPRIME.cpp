#include <bits/stdc++.h>
using namespace std;

#define task "COPRIME"
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
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;
ll n, a[N], dp[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
bool check(ll x, ll y){
    return (__gcd(x, y) == 1);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (a[i] > a[j] && check(a[i], a[j])){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    ll maxs = -INF;
    for (int i = 1; i <= n; i++){
        maxs = max(maxs, dp[i]);
    }
}

int main() {
    tassk();
    solve();
    return 0;
}