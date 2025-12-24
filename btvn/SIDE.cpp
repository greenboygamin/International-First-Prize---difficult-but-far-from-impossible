#include <bits/stdc++.h>
using namespace std;

#define task "SIDE"
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
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

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
    ll x0, y0, x1, y1, a, b, c;
    cin >> x0 >> y0 >> x1 >> y1 >> a >> b >> c;
    ll v1 = a * x0 + b * y0 + c;
    ll v2 = a * x1 + b * y1 + c;
    
    if (v1 * v2 > 0) cout << "YES" << el;
    else cout << "NO" << el;
}

int main() {
    tassk();
    solve();
    return 0;
}