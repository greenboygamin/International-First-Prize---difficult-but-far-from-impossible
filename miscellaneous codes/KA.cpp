#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
typedef long long int ll;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<ll> c;
    c.insert(0); 
    ll cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (c.find(cur) != c.end()) {
            ans++;
            c.clear();
            c.insert(0);
            cur = 0; 
        }
        c.insert(cur);
    }

    cout << ans << el;
}

int main() {
    tassk();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
