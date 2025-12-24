#include <bits/stdc++.h>
using namespace std;

#define task "LONELY"
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
const ll N = 1005;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

struct P {
    ll x, y;
};

P a[N];
int n;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int sg(ll x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

ll cp(P u, P v, P w) {
    return (v.x - u.x) * (w.y - u.y) - (v.y - u.y) * (w.x - u.x);
}

bool cut(P p1, P p2, P p3, P p4) {
    ll c1 = cp(p1, p2, p3);
    ll c2 = cp(p1, p2, p4);
    ll c3 = cp(p3, p4, p1);
    ll c4 = cp(p3, p4, p2);
    if (sg(c1) * sg(c2) < 0 && sg(c3) * sg(c4) < 0) return true;
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool ok = true;
            for (int k = 1; k <= n; k++) {
                if (!ok) break;
                for (int l = k + 1; l <= n; l++) {
                    if (k == i || k == j || l == i || l == j) continue;
                    if (cut(a[i], a[j], a[k], a[l])) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}