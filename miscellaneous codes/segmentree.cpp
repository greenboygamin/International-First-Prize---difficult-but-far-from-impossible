#include <bits/stdc++.h>
using namespace std;

#define task ""
#define ll long long int
#define ld long double
#define el "\n"

const ll N = 1e6 + 2;
const ll INF = 1e9 + 7;
ll stmin[4 * N], stsum[4 * N], stmax[4 * N], a[N], n, x, y, q;
char type;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void buildmax(ll id, ll l, ll r) {
    if (l == r) {
        stmax[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildmax(id * 2, l, mid);
    buildmax(id * 2 + 1, mid + 1, r);
    stmax[id] = max(stmax[id * 2], stmax[id * 2 + 1]);
}

void buildmin(ll id, ll l, ll r) {
    if (l == r) {
        stmin[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildmin(id * 2, l, mid);
    buildmin(id * 2 + 1, mid + 1, r);
    stmin[id] = min(stmin[id * 2], stmin[id * 2 + 1]);
}

void buildsum(ll id, ll l, ll r){
    if (l == r){
        stsum[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildsum(id * 2, l, mid);
    buildsum(id * 2 + 1, mid + 1, r);
    stsum[id] = stsum[id * 2] + stsum[id * 2 + 1];
}

void updatemax(ll id, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        stmax[id] = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if (pos <= mid) updatemax(id * 2, l, mid, pos, val);
    else updatemax(id * 2 + 1, mid + 1, r, pos, val);
    stmax[id] = max(stmax[id * 2], stmax[id * 2 + 1]);
}

void updatemin(ll id, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        stmin[id] = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if (pos <= mid) updatemin(id * 2, l, mid, pos, val);
    else updatemin(id * 2 + 1, mid + 1, r, pos, val);
    stmin[id] = min(stmin[id * 2], stmin[id * 2 + 1]);
}

void updatesum(ll id, ll l, ll r, ll pos, ll val) {
    if (l == r){
        stsum[id] = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if (pos <= mid) updatesum(id * 2, l, mid, pos, val);
    else updatesum(id * 2 + 1, mid + 1, r, pos, val);
    stsum[id] = stsum[id * 2] + stsum[id * 2 + 1];
}

ll getmax(ll id, ll l, ll r, ll u, ll v) {
    if (u > r || v < l) return -INF;
    if (u <= l && r <= v) return stmax[id];
    ll mid = (l + r) >> 1;
    return max(getmax(id * 2, l, mid, u, v), getmax(id * 2 + 1, mid + 1, r, u, v));
}

ll getmin(ll id, ll l, ll r, ll u, ll v) {
    if (u > r || v < l) return INF;
    if (u <= l && r <= v) return stmin[id];
    ll mid = (l + r) >> 1;
    return min(getmin(id * 2, l, mid, u, v), getmin(id * 2 + 1, mid + 1, r, u, v));
}

ll getsum(ll id, ll l, ll r, ll u, ll v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return stsum[id];
    ll mid = (l + r) >> 1;
    return getsum(id * 2, l, mid, u, v) + getsum(id * 2 + 1, mid + 1, r, u, v);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    buildmax(1, 1, n);
    buildmin(1, 1, n);
    buildsum(1, 1, n);
    
    while (q--) {
        cin >> type >> x >> y;
        if (type == 'C') {
            updatemax(1, 1, n, x, y);
            updatemin(1, 1, n, x, y);
            updatesum(1, 1, n, x, y);
            a[x] = y;
        } else if (type == 'L') {
            cout << getmin(1, 1, n, x, y) << el;
        } else if (type == 'H') {
            cout << getmax(1, 1, n, x, y) << el;
        } else if (type == 'S') {
            cout << getsum(1, 1, n, x, y) << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
