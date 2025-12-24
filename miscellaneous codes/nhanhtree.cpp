#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli MAX = 1e5+5;
lli segMin[4*MAX],segMax[4*MAX],segSum[4*MAX],a[MAX],n,q;
void udmin(lli id,lli l,lli r){
    if(l == r) {
        segMin[id] = a[l];
        return;
    }
    lli mid = (l + r) / 2;
    udmin(2 * id, l, mid);
    udmin(2 * id + 1, mid + 1, r);
    segMin[id] = min(segMin[2 * id], segMin[2 * id + 1]);
}
void udmax(lli id, lli l, lli r){
    if (l == r) {
        segMax[id] = a[l];
        return;
    }
    lli mid = (l + r) / 2;
    udmax(2 * id, l, mid);
    udmax(2 * id + 1, mid + 1, r);
    segMax[id] = max(segMax[2 * id], segMax[2 * id + 1]);
}
void udsum(lli id, lli l, lli r) {
    if (l == r) {
        segSum[id] = a[l];
        return;
    }
    lli mid = (l + r) / 2;
    udsum(2 * id, l, mid);
    udsum(2 * id + 1, mid + 1, r);
    segSum[id] = segSum[2 * id] + segSum[2 * id + 1];
}
void update(lli id, lli l, lli r, lli i, lli val) {
    if (l == r) {
        segMin[id] = segMax[id] = segSum[id] = val;
        return;
    }
    lli mid = (l + r) / 2;
    if (i <= mid) update(2 * id, l, mid, i, val);
    else update(2 * id + 1, mid + 1, r, i, val);
    segMin[id] = min(segMin[2 * id], segMin[2 * id + 1]);
    segMax[id] = max(segMax[2 * id], segMax[2 * id + 1]);
    segSum[id] = segSum[2 * id] + segSum[2 * id + 1];
}
lli qumin(lli id, lli l, lli r, lli u, lli v) {
    if (v < l || u > r) return INT_MAX;
    if (u <= l && r <= v) return segMin[id];
    lli mid = (l + r) / 2;
    return min(qumin(2 * id, l, mid, u, v), qumin(2 * id + 1, mid + 1, r, u, v));
}
lli qumax(lli id, lli l, lli r, lli u, lli v) {
    if (v < l || u > r) return INT_MIN;
    if (u <= l && r <= v) return segMax[id];
    lli mid = (l + r) / 2;
    return max(qumax(2 * id, l, mid, u, v), qumax(2 * id + 1, mid + 1, r, u, v));
}
lli qusum(lli id, lli l, lli r, lli u, lli v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return segSum[id];
    lli mid = (l + r) / 2;
    return qusum(2 * id, l, mid, u, v) + qusum(2 * id + 1, mid + 1, r, u, v);
}

int main() {
    cin >> n >> q;
    for (lli i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    udmin(1, 1, n);
    udmax(1, 1, n);
    udsum(1, 1, n);
    while (q--) {
        char type;
        lli l, r;
        cin >> type >> l >> r;
        if (type == 'C') {
            update(1, 1, n, l, r);
        } else if (type == 'L') {
            cout << qumin(1, 1, n, l, r) << endl;
        } else if (type == 'H') {
            cout << qumax(1, 1, n, l, r) << endl;
        } else if (type == 'S') {
            cout << qusum(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}