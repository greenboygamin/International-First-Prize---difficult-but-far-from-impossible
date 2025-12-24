#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

int n, q;
ll st[4 * N], a[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void update(int id, int l, int r, int pos, ll val){
    if (pos < l || r < pos) return;
    if (l == r){
        st[id] = max(st[id], val);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}


int main() {
    tassk();
    solve();
    return 0;
}   