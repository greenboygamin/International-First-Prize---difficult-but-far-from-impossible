#include <bits/stdc++.h>
using namespace std;
#define task "SELESHIRT"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, m, x, y, ans = 0;
vpll v;
void tassk(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
struct clo {
    ll gt, vt;
};
bool ss(const clo &m, const clo &n){
    return m.gt <= n.gt;
}
clo a[N], b[N];
ll tknp(ll l, ll r, ll k){
    ll pos = -1;
    while (l <= r){
        ll mid = l + r >> 1;
        if (a[mid].gt - x <= k and k <= a[mid].gt + y){
            pos = mid;
            r = mid - 1;
        }
        else if (k < a[mid].gt - x) r = mid - 1;
        else l = mid + 1;
    }
    return pos;
}
void solve(){
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++){
        cin >> a[i].gt;
        a[i].vt = i;
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i].gt;
        b[i].vt = i;
    }
    sort(a + 1, a + n + 1, ss);
    sort(b + 1, b + m + 1, ss);
    ll p = 0, z;
    for (int i = 1; i <= m; i++){
        z = tknp(p + 1, n, b[i].gt);
        if (z != -1){
            ans++;
            v.pb({a[z].vt, b[i].vt});
            p = z;
        }
    }
    cout << ans << el;
    for (auto i : v) cout << i.first << " " << i.second << el;
}
int main()
{
    tassk();
    solve();
    return 0;
}