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
    int a, b;
    cin >> a >> b;
    if (a >= b){
        cout << a << el;
        return;
    }
    else {
        /*
        int l = min(a, b - a), r = max(a, b - a), res = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (a - mid >= b - 2 * mid && 1 <= mid && mid < a){
                r = mid - 1;
                res = a - mid;
            }
            else l = mid + 1;
        }
        cout << res << el;*/
        int res = a - b + a;
        if (res < 0) res = 0;
        cout << res << el;
    }
}

int main() {
    tassk(); int t; cin >> t; while (t--)
    solve();
    return 0;
}
 