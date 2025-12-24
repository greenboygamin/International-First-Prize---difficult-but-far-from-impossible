#include <bits/stdc++.h>
using namespace std;

#define task "SPHOTO"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef vector<long long> vll;

const ll N = 1e6 + 5;
ll n, b[N], last[N], uniq[N], a[N], val[N], segA[4*N], segVal[4*N], lazy[4*N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void propagate(int node, int l, int r) {
    if (lazy[node] != 0) {
        segVal[node] += segA[node] * lazy[node];
        if (l != r) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// Hàm cập nhật mảng a và uniq, sử dụng Segment Tree
void update(int node, int l, int r, int uL, int uR, int value) {
    propagate(node, l, r);
    if (l > uR || r < uL) return;
    if (l >= uL && r <= uR) {
        lazy[node] += value;
        propagate(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2*node, l, mid, uL, uR, value);
    update(2*node+1, mid+1, r, uL, uR, value);
    segA[node] = segA[2*node] + segA[2*node+1];
    segVal[node] = segVal[2*node] + segVal[2*node+1];
}

// Hàm truy vấn Segment Tree
ll query(int node, int l, int r, int qL, int qR) {
    propagate(node, l, r);
    if (l > qR || r < qL) return 0;
    if (l >= qL && r <= qR) return segVal[node];
    int mid = (l + r) / 2;
    return query(2*node, l, mid, qL, qR) + query(2*node+1, mid+1, r, qL, qR);
}

void solve() {
    cin >> n;
    map<ll, ll> lastPos;
    for (int i = 1; i <= n; i++) cin >> b[i];

    ll result = 0;
    for (int r = 1; r <= n; r++) {
        ll pr = lastPos[b[r]];  // Vị trí gần nhất mà br đã xuất hiện
        if (pr > 0) update(1, 1, n, pr, pr, -1);  // Giảm uniq ở vị trí cũ
        
        lastPos[b[r]] = r;
        update(1, 1, n, r, r, 1);  // Tăng uniq ở vị trí mới
        
        // Tính toán các giá trị từ pr + 1 đến r - 1
        result += query(1, 1, n, pr+1, r-1);
    }
    
    cout << result << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
