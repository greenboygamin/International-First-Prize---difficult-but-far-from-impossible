#include <bits/stdc++.h>
using namespace std;

#define task "CSC"
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
ll a[4], s = 0;
//
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    for (int i = 1; i <= 3; i++) cin >> a[i], s += a[i];
    sort(a + 1, a + 3 + 1);
    ll dif = min(a[2] - a[1], a[3] - a[2]);
    //cout << a[1] << " " << a[2] << " " << a[3] << el;
    ll an = a[1] + 3 * dif;
    cout << 2 * (a[1] + an) - s << el;
    //cout << dif;
}

int main() {
    tassk();
    solve();
    return 0;
}
