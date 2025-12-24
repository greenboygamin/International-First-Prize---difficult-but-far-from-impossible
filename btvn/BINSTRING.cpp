#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
typedef long long int ll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;

const int N = 1e5 + 5;
int st[4 * N];
string s;
int n, q;

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = s[l] - '0';
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

ll bintodec(int l, int r) {
    ll res = 0, base = 1;
    for (int i = r; i >= l; --i) {
        res = (res + get(1, 1, n, i, i) * base);
        base *= 2;
    }
    return res;
}

void DELETE(int pos) {
    if (pos < 1 || pos > n) return;
    s.erase(s.begin() + pos);
    n--;
    build(1, 1, n);
}

void solve() {
    cin >> s;
    s = " " + s;
    n = s.size() - 1;
    cin >> q;
    build(1, 1, n);
    while (q--) {
        string type;
        int x, y;
        cin >> type;
        if (type == "STR") {
            cin >> x >> y;
            if (x < 1 || y > n || x > y) {
                cout << "0" << el;
            } else {
                cout << bintodec(x, y) << el;
            }
        } else if (type == "DEL") {
            cin >> x;
            DELETE(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
