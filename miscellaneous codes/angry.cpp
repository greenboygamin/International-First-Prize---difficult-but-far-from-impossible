#include <bits/stdc++.h>
using namespace std;
#define task "angry"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], ans, k;
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
    ll i = 1, d = 0;
    while (i <= n){
        d++;
        ll pos = a[i] + 2 * x;
        while(a[i] <= pos && i <= n){
            i++;
        }
    }
    return d <= k;
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 1, r = 1e9;
    while (l <= r){
        ll mid = (l + r) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
int main()
{
    tassk();
    solve();
    return 0;
}