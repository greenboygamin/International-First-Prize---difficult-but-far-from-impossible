#include <bits/stdc++.h>
using namespace std;
#define task "cspip"
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

struct Point {
    ll x, y;
};

ll cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool on_segment(Point p, Point a, Point b) {
    if (cross_product(a, b, p) != 0) return false;
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

int n, m;
vector<Point> poly;

void solve_point(Point p) {
    for (int i = 0; i < n; ++i) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];
        if (on_segment(p, p1, p2)) {
            cout << "BOUNDARY" << el;
            return;
        }
    }

    bool inside = false;
    for (int i = 0; i < n; ++i) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];
        bool in_y_range = (p1.y > p.y) != (p2.y > p.y);
        
        if (in_y_range) {
            ll cp = cross_product(p1, p2, p);
            if (p2.y > p1.y && cp > 0) inside = !inside;
            else if (p2.y < p1.y && cp < 0) inside = !inside;
        }
    }

    if (inside) cout << "INSIDE" << el;
    else cout << "OUTSIDE" << el;
}

void solve() {
    cin >> n >> m;
    poly.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> poly[i].x >> poly[i].y;
    }

    for (int i = 0; i < m; ++i) {
        Point p;
        cin >> p.x >> p.y;
        solve_point(p);
    }
}

int main() {
    tassk();
    solve();
    return 0;
}