#include <bits/stdc++.h>
using namespace std;

#define task "GIAODIEM"
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
    ll a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    ll d = a1 * b2 - a2 * b1;
    ll dx = b1 * c2 - b2 * c1;
    ll dy = c1 * a2 - c2 * a1;
    
    cout << fixed << setprecision(6) << (ld)dx / d << " " << (ld)dy / d << el;
}

int main() {
    tassk();
    solve();
    return 0;
}