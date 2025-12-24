#include <bits/stdc++.h>
using namespace std;

#define task "dgmove"
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
const ll MOD = 998244353;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll pows(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll proc(ll x){
    vector<ll> digits;
    ll tmp = x, maxs = x;
    while (tmp){
        digits.pb(tmp % 10);
        tmp /= 10;
    }
    ll n = digits.size();
    digits.pb(0);
    reverse(digits.begin(), digits.end());
    ll cur = 0, sub = 0;
    for (int i = 1; i <= n; i++){
        cur = cur * 10 + digits[i];
        if (i > 1) sub = sub * 10 + digits[i - 1];
        ll rems = pows(10, n - i);
        ll cu = x - (cur - sub) * rems;
        ll opt1 = cu * 10 + digits[i];
        ll opt2 = cu + digits[i] * pows(10, n - 1);
        maxs = max({maxs, opt1, opt2});
        //cout << cu << " " << cu * 10 + digits[i] << "  " << cu + digits[i] * pows(10, n - 1) << el;
    }
    //cout << el;
    return maxs;
}

void solve() {
    ll a; cin >> a;
    cout << proc(a) << el;
}


int main() {
    tassk(); int t; cin >> t; while (t--)
    solve();
    return 0;
}   