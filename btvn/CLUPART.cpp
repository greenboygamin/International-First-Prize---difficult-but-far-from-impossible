#include <bits/stdc++.h>
using namespace std;
#define task "CLUPART"
#define ll long long int
#define ld long double
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], dp[N], tv[N];
ld e;
vll v;
ll amin = INT_MAX, amax = INT_MIN;
//code cua HoaRoiCuaPhatVanVatCuiDau
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
    cin >> n >> e;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++){
        amin = INT_MAX; amax = INT_MIN; dp[i] = INT_MAX;
        for (int j = i; j >= 1; j--){
            amin = min(amin, a[j]);
            amax = max(amax, a[j]);
            if (double(i - j + 1) / double(amax - amin + 1) >= e && dp[i] > dp[j - 1] + 1){
                dp[i] = dp[j - 1] + 1;
                tv[i] = j - 1;
            }
        }
    }
    cout << dp[n] << el;
    ll i = n;
    while(i > 0){
        v.pb(i);
        i = tv[i];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
