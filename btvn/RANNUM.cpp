#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli inf=1e13, N=1e6+7;
lli n, a[N], ans, c[N];
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("RANNUM.inp", "r")) {
        freopen("RANNUM.inp", "r", stdin);
        freopen("RANNUM.out", "w", stdout);
    }
}
bool check(lli x)
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= x; i++) c[a[i] + 1000] += 1;
    for (int i = x + 1; i <= n; i++)
    { 
        if ( c[a[i] + 1000] > 0)  c[a[i] + 1000]++;
        c[a[i - x] + 1000] --;
    }
    for (int i = 0 ; i <= 2000; i++)
    {
        if (c[i] > 0) return true;
    }
    return false;
}
void Solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    lli l = 1, r = n / 2 + 1;
    while (l <= r)
    {
        lli mid = (l + r) / 2;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}
int main()
{
    Task();
    Solve();
    return 0;
}