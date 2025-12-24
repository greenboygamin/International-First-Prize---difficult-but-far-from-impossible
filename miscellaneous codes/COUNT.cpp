#include <bits/stdc++.h>
using namespace std;
#define task "COUNT"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], k, t, c;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

pair<bool, ll> check(ll x) {
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 1; i + x - 1 <= n; i++) {
        ll cursum = prefix[i + x - 1] - prefix[i - 1];
        ll reqsum = a[i + x - 1] * x;
        ll dem = reqsum - cursum;

        if (dem <= k) return {true, a[i + x - 1]};
    }
    return {false, -1};
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        auto res = check(mid);
        if (res.first) {
            t = mid;
            c = res.second;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << t << " " << c;
}

int main() {
    tassk();
    solve();
    return 0;
}
