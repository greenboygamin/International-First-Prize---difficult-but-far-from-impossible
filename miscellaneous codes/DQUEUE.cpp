#include <bits/stdc++.h>
using namespace std;
#define task "DQUEUE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, t, a[N], st[1 << 20];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void build(ll id, ll l, ll r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    ll mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
ll get(ll id, ll l, ll r, ll u, ll v){
    if (u > r || v < l) return LLONG_MAX;
    if (u <= l && v >= r) return st[id];
    ll mid = l + r >> 1;
    ll left = get(id * 2, l, mid, u, v);
    ll right = get(id * 2 + 1, mid + 1, r, u, v);
    return min(left, right);
}
void solve() {
    int i, j; cin >> i >> j;
    cout << get(1, 1, n, i, j) << el;
}
int main() {
    tassk();
    cin >> n >> t;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (t--)
    solve();
    return 0;
}
