#include <bits/stdc++.h>
using namespace std;
#define task "WATER"
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
ll n, a[N], l[N], r[N]; deque<ll> dq;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    l[1] = a[1]; r[n] = a[n];
    for (int i = 2; i <= n; i++){
        l[i] = max(l[i - 1], a[i]);
    }
    for (int i = n - 1; i >= 1; --i){
        r[i] = max(r[i + 1], a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans += max(0LL, min(l[i], r[i]) - a[i]);
    }
    cout << ans;
}
int main() {
    tassk();
    solve();
    return 0;
}