#include <bits/stdc++.h>
using namespace std;

#define task "EUREKA"
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
const ll MOD = 123456789;

int n;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

void solve() {
    cin >> n;
    vector<ll> h(n + 1);
    vector<ll> H(n + 1);
    ll maxh = INT_MIN, pos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        H[i] = h[i];  
    }
    for (int i = 2; i <= n; i++){
        ll mins = H[i - 1] - 1;
        if (H[i] < mins) H[i] = mins;
    }
    for (int i = n - 1; i >= 1; i--){
        ll mins = H[i + 1] - 1;
        if (H[i] < mins) H[i] = mins; 
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += H[i] - h[i];
    
    cout << ans << el;
}

int main() {
    tassk(); int t; cin >> t; while (t--)
    solve();
    return 0;
}   