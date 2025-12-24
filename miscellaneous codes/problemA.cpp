#include <bits/stdc++.h>
using namespace std;

#define task "A"
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    int n; cin >> n;
    int maxs = INT_MIN, mins = INT_MAX;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        mins = min(mins, x);
        maxs = max(maxs, x);
    }
    cout << (maxs - mins) * (n - 1) << el;
}

int main() {
    tassk(); int t; cin >> t; while (t--)
    solve();
    return 0;
}
 