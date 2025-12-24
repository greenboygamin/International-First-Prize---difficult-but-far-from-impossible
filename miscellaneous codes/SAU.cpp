#include <bits/stdc++.h>
using namespace std;

#define task "CONSAU"
typedef long long ll;
typedef pair<ll, ll> pll;
#define el "\n"
const ll N = 1e6 + 5;
pll a[N];
ll c[N];
ll n;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
bool check(ll x){
    ll sum = a[x].first;
    for (int i = 1; i <= n; i++){
        if (i == x) continue;
        if (a[i].first >= sum) return 0;
        sum += a[i].first;
    }
    return 1;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    ll l = 1, r = n, res;
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (check(mid)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    vector<string> ans(N);
    for (int i = 1; i <= n; i++){
        if (i < res){
            ans[a[i].second] = "N";
        }
        else ans[a[i].second] = "T";
    }
    for (auto i : ans) cout << i;
}

int main() {
    tassk();
    solve();
    return 0;
}
