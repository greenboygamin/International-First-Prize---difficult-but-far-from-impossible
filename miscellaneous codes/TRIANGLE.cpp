#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli inf=1e13, N=1e6+7;
lli n, a[N], b[N], c[N], x , y, dem = 0;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("TRIANGLE.inp", "r")) {
        freopen("TRIANGLE.inp", "r", stdin);
        freopen("TRIANGLE.out", "w", stdout);
    }
}
void Solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort (a + 1, a + n + 1);
    sort (b + 1, b + n + 1);
    sort (c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            x = abs(a[i] - b[j]); y = a[i] + b[j];
            lli k1 = upper_bound(c + 1, c + n + 1, x) - c;
            lli k2 = lower_bound(c + 1, c + n + 1, y) - c - 1;
            if (k1 <= k2) dem += k2 - k1 + 1;
        }
    }
    cout << dem ;
}
int main()
{
    Task();
    Solve();
    return 0;
}