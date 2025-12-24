#include <bits/stdc++.h>
using namespace std;
#define task "RECT"
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
ll n, m, a[N], b[N], l[N], r[N], l1[N], r1[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll findrange(ll h[], ll l[], ll r[]){
    ll maxs = -1e9;
    stack<ll> s;
    for (int i = 1; i <= n; i++){
        while (!s.empty() && h[s.top()] >= h[i]) s.pop();
        if (s.empty()) l[i] = 0;
        else l[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i > 0; i--){
        while (!s.empty() && h[s.top()] >= h[i]) s.pop();
        if (s.empty()) r[i] = 1 + n;
        else r[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++){
        maxs = max(maxs, h[i] * (r[i] - l[i] - 1));
    }
    return maxs;
}
void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = m - a[i];
    }
    ll maxa = findrange(a, l, r), maxb = findrange(b, l1, r1);
    cout << max(maxa, maxb);
}
int main() {
    tassk();
    solve();
    return 0;
}