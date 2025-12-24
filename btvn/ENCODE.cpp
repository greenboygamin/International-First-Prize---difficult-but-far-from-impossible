#include <bits/stdc++.h>
using namespace std;
#define task "ENCODE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll l, r, a, k;
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
void solve() {
    cin >> l >> r >> a >> k;
    ll m = k / __gcd(a, k);
    ll ans = floor(r / m) - floor((l - 1) / m);
    cout << ans;
}
int main()
{
    tassk();
    solve();
    return 0;
}