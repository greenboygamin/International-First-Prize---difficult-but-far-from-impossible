#include <bits/stdc++.h>
using namespace std;
#define task "LINEGAME"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, a[N], dp1[N], dp2[N], b[N], x;
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
    for (int i = 1; i <= n; i++){
        cin >> x;
        a[i] = x; b[i] = -x;
    }
    for (int i = 1; i <= n + 1; i++){
        dp1[i] = max(dp1[i - 1], dp2[i - 1] + a[i]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + b[i]);
    }
    cout << max(dp1[n + 1], dp2[n + 1]);
}
int main()
{
    tassk();
    solve();
    return 0;
}
