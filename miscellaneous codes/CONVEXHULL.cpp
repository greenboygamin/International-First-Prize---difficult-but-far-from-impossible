#include <bits/stdc++.h>
using namespace std;

#define task "CONVEXHULL"
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

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

struct Point { ll x, y; };
bool ss (const Point &a, const Point &b){
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
ll cross(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    sort(pts.begin(), pts.end(), ss);
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    int lower_sz = hull.size();
    for (int i = n-2; i >= 0; i--) {
        while ((int)hull.size() > lower_sz && cross(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    if (hull.size() > 1) hull.pop_back();

    int m = hull.size();
    ll s2 = 0;
    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        s2 += hull[i].x * hull[j].y - hull[j].x * hull[i].y;
    }
    s2 = llabs(s2);
    int start = 0;
    for (int i = 1; i < m; i++) {
        if (hull[i].y < hull[start].y || (hull[i].y == hull[start].y && hull[i].x < hull[start].x)) {
            start = i;
        }
    }
    cout << m << "\n";
    cout << fixed << setprecision(1) << (s2 / 2) << "." << (s2 % 2 ? 5 : 0) << "\n";
    for (int k = 0; k < m; k++) {
        int idx = (start + k) % m;
        cout << hull[idx].x << " " << hull[idx].y << "\n";
    }
}

int main() {
    tassk();
    solve();
    return 0;
}   