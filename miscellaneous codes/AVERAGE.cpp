#include <bits/stdc++.h>
using namespace std;
#define task "AVERAGE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define ld long double
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, k, a[N], ans, prf[N];
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
bool check(ll x){
    memset(prf, 0, sizeof prf);
    prf[0] = 0;
    for (int i = 1; i <= n; i++){
        prf[i] = prf[i - 1] + (a[i] - x);
    }
    ll bmin = 0;
    for (int i = k; i <= n; i++){
        if (prf[i] >= bmin) return true;
        bmin = min(bmin, prf[i - k + 1]);
    }
    return false;
}
void solve() {
    cin >> n >> k;
    ll mins = 1e12, maxs = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] *= 100000;
        mins = min(mins, a[i]);
        maxs = max(maxs, a[i]);
    }
    ll l = mins, r = 1e12;
    while (l <= r){
        ll mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << fixed << setprecision(3) << ans / 100000.0;
}
int main()
{
    tassk();
    solve();
    return 0;
}