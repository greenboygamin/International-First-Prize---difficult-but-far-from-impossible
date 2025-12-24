#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll N = 1e5 + 5; 
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18; 

ll dp[N];
ll n, a, b;

ll calc(ll k) {
    if (k == 1) return 0;
    if (dp[k] != -1) return dp[k];

    ll l = 1, r = k - 1;
    ll m_opt = 1;
    
    while(l <= r){
        ll m = (l + r) / 2;
        if(a + calc(m) < b + calc(k-m)){
            m_opt = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    ll c1 = max(a + calc(m_opt), b + calc(k - m_opt));
    ll c2 = INF;
    if (m_opt < k - 1) {
         c2 = max(a + calc(m_opt + 1), b + calc(k - (m_opt + 1)));
    }

    return dp[k] = min(c1, c2);
}

void solve_test() {
    cin >> n >> a >> b;
    for(int i = 0; i <= n; i++) dp[i] = -1;
    cout << calc(n) << el;
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve() {
    int q;
    cin >> q;
    while(q--) {
        solve_test();
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}