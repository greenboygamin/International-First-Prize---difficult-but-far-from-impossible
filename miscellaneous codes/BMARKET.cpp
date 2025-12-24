#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll y, k, n; vector<ll> res;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("BMARKET.inp", "r")) {
        freopen("BMARKET.inp", "r", stdin);
        freopen("BMARKET.out", "w", stdout);
    }
}
void Solve() {
    cin >> y >> k >> n;
    ll start = k - y % k;
    if (start + y > n) {
        cout << -1;
        return;
    }
    for (ll i = start; i <= n - y; i += k) {
        res.push_back(i);
    }
    if (res.empty()) cout << -1;
    else for (auto i : res) cout << i << " ";
}
int main() {
    Task();
    Solve();
    return 0;
}

