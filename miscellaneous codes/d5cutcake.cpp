#include <bits/stdc++.h>
using namespace std;
#define task "catbanh"
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
    int t;
    cin >> t;
    while(t--) {
        ll ar[3], d;
        cin >> ar[0] >> ar[1] >> ar[2] >> d;
        sort(ar, ar + 3);
        ll a = ar[0], b = ar[1], c = ar[2];
        ll s = a + b + c - d;
        ll x, y, z;
        if (a * 3 < s) {
            x = a;
            ll r = s - x;
            if (b * 2 < r) {
                y = b;
                z = r - y;
            } else {
                y = r / 2;
                z = r - y;
            }
        } else {
            x = s / 3;
            ll r = s - x;
            y = r / 2;
            z = r - y;
        }
        cout << x * y * z << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}