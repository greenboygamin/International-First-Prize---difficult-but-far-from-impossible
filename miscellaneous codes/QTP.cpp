#include <bits/stdc++.h>
using namespace std;

#define task "QTP"
#define el "\n"

typedef long long int ll;

const ll INF = 1e9 + 7;
ll n, h[10000007];

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
    for (int i = 1; i <= n; i++) cin >> h[i];
    ll tmp = 0, dem = 0;
    for (int i = n; i >= 1; --i){
        if (h[i] == 0 || tmp > h[i]){
            tmp++;
        }
        else {
            tmp = 0;
        }
        dem = max(dem, tmp + 1);
    }
    dem = max(dem, tmp + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = n; i >= 1; --i){
        if (dem > h[i]){
            tmp++;
        }
        else {
            tmp = 0;
        }
        dem = max(dem, tmp + 1);
    }
    cout << dem;
}

int main() {
    tassk();
    solve();
    return 0;
}
