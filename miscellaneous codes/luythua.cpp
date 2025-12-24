#include <bits/stdc++.h>
using namespace std;

#define task "luythua"
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
const ll MOD = 1e9 + 7;
ll l, r, val, x, i;
vll ans(41);

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> l >> r;
    for (int k = 39; k >= 1; k--){
        x = 2;
        while (pow(x, k) < l){
            x++;
        }
        if (pow(x, k) <= r){
            cout << "Case #" << i << ": " << k << el;
            return;
        }
    }
}

int main() {
    tassk();
    ll t; 
    cin >> t; 
    for (i = 1; i <= t; i++) solve();
    return 0;
}
