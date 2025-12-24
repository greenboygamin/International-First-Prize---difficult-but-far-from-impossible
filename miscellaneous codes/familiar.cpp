#include <bits/stdc++.h>
using namespace std;
#define task "familiar"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], ans;
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
    for (int i = 1; i <= x; i++){
        if (a[i] + i > a[x] + n) return false;
    }
    return true;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll l = 1, r = n;
    sort(a + 1, a + n + 1, greater<ll>());
    while (l <= r){
        ll mid = l + r >> 1;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}
int main()
{
    tassk();
    solve();
    return 0;
}