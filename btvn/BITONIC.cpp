#include <bits/stdc++.h>
using namespace std;
#define task "BITONIC"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e6;
ll n, a[N], dp1[N], dp2[N];
vll v;
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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp1[0] = 0; dp2[n + 1] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                dp1[i] = max(dp1[i], dp1[j] + a[i]);
            }
        }
    }
    for (int i = n; i >= 1; i--){
        for (int j = n + 1; j > i; j--){
            if (a[i] > a[j]){
                dp2[i] = max(dp2[i], dp2[j] + a[i]);
            }
        }
    }
    ll maxs = INT_MIN;
    for (int i = 2; i <= n; i++){
        maxs = max(maxs, dp1[i] + dp2[i] - a[i]);
    }
    cout << maxs;
}
int main()
{
    tassk();
    solve();
    return 0;
}
