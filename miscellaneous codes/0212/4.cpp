#include <bits/stdc++.h>
using namespace std;
#define task "MagicGallery"
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
const ll N = 505;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;
const int SMAX = 250005;

int n, m, q, S, sh = 0;
int a[N][N];
int pr[SMAX], pc[SMAX];

struct Node {
    int r1, r2, c1, c2;
} t[4 * SMAX];

void up(int k) {
    t[k].r1 = min(t[2 * k].r1, t[2 * k + 1].r1);
    t[k].r2 = max(t[2 * k].r2, t[2 * k + 1].r2);
    t[k].c1 = min(t[2 * k].c1, t[2 * k + 1].c1);
    t[k].c2 = max(t[2 * k].c2, t[2 * k + 1].c2);
}

void build(int k, int l, int r) {
    if (l == r) {
        t[k] = {pr[l], pr[l], pc[l], pc[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    up(k);
}

void upd(int k, int l, int r, int i) {
    if (l == r) {
        t[k] = {pr[l], pr[l], pc[l], pc[l]};
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) upd(2 * k, l, mid, i);
    else upd(2 * k + 1, mid + 1, r, i);
    up(k);
}

int get(int k, int l, int r, int R1, int C1, int R2, int C2, int u, int v) {
    if (l > v || r < u) return -1;
    if (t[k].r1 >= R1 && t[k].r2 <= R2 && t[k].c1 >= C1 && t[k].c2 <= C2) return -1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    int res = get(2 * k, l, mid, R1, C1, R2, C2, u, v);
    if (res != -1) return res;
    return get(2 * k + 1, mid + 1, r, R1, C1, R2, C2, u, v);
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m;
    S = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pr[a[i][j]] = i;
            pc[a[i][j]] = j;
        }
    }
    build(1, 0, S - 1);
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int v1 = a[r1][c1];
            int v2 = a[r2][c2];
            swap(a[r1][c1], a[r2][c2]);
            pr[v1] = r2; pc[v1] = c2;
            pr[v2] = r1; pc[v2] = c1;
            upd(1, 0, S - 1, v1);
            upd(1, 0, S - 1, v2);
        } else if (type == 2) {
            int w;
            cin >> w;
            sh = (sh + w) % S;
        } else {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int st = (0 - sh + S) % S;
            int res = get(1, 0, S - 1, r1, c1, r2, c2, st, S - 1);
            if (res == -1 && st > 0) {
                res = get(1, 0, S - 1, r1, c1, r2, c2, 0, st - 1);
            }
            if (res != -1) cout << (res + sh) % S << el;
            else cout << -1 << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}