#include <bits/stdc++.h>
using namespace std;

#define task "SFUNC"
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

ll n;
map<pll, ll> memo;
ll g[4] = {1, -1, -1, 1}; 

ll calc(ll num, int fp) {
    if (num > n) return 0;
    
    if (memo.count({num, fp})) {
        return memo[{num, fp}];
    }

    int fc = fp + g[num % 4];
    ll ans = (fc == 0 ? 1 : 0);
    
    ans += calc(num * 2, fc);
    ans += calc(num * 2 + 1, fc);
    
    return memo[{num, fp}] = ans;
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
    cin >> n;
    ll ans = (n >= 1 ? 1 : 0); 
    if (n >= 2) {
        ans += calc(2, 0); 
    }
    if (n >= 3) {
        ans += calc(3, 0);
    }
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}