#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"

const int N = 1e5 + 5;
int st[4 * N], lazy[4 * N];
bool toggle[4 * N];
int n, q;

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void propagate(int id, int l, int r) {
    if (toggle[id]) {
        st[id] = (r - l + 1) - st[id];
        if (l != r) {
            toggle[id * 2] = !toggle[id * 2];
            toggle[id * 2 + 1] = !toggle[id * 2 + 1];
        }
        toggle[id] = false;
    }
}

void update(int id, int l, int r, int u, int v) {
    propagate(id, l, r);
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        toggle[id] = !toggle[id];
        propagate(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    propagate(id, l, r);
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve() {
    cin >> n >> q;
    build(1, 1, n);
    while (q--) {
        char type;
        int x, y;
        cin >> type >> x >> y;
        if (type == '0') {
            update(1, 1, n, x, y);
        } else if (type == '1') {
            cout << get(1, 1, n, x, y) << el;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
