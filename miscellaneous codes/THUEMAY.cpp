#include <bits/stdc++.h>
using namespace std;
#define task "THUEMAY"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e6;
ll n, tv[N];
struct thue {
    ll a, b, c, vt;
}; 
thue xe[N];
struct so{
    ll a, b;
};
so dp[N];
bool ss(const thue &x, const thue &y){
    if (x.b == y.b){
        if (x.a == y.a) return x.c < y.c;
        return x.a < y.a;
    }
    return x.b < y.b;
}
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
    for (int i = 1; i <= n; i++) cin >> xe[i].a >> xe[i].b >> xe[i].c, xe[i].vt = i;
    sort(xe + 1, xe + n + 1, ss);
    //for (int i = 1; i <= n; i++) cout << xe[i].a << " " << xe[i].b << " " << xe[i].c << el;
    for (int i = 1; i <= n; i++){
        dp[i].a = xe[i].c;
        dp[i].b = 1;
        for (int j = 1; j < i; j++){
            if (xe[j].b <= xe[i].a){
                if (dp[i].a <= xe[i].c + dp[j].a){
                    dp[i].a = xe[i].c + dp[j].a;
                    dp[i].b = 1 + dp[j].b;
                    tv[xe[i].vt] = xe[j].vt;
                }
            }
        }
    }
    ll maxs = LLONG_MIN, maxx, pos;
    for (int i = 1; i <= n; i++){
        if (maxs <= dp[i].a){
            maxs = dp[i].a;
            maxx = dp[i].b;
            pos = xe[i].vt;
        }
    }
    cout << maxx << " " << maxs << el;
    vll ans;
    while (pos != 0){
        ans.pb(pos);
        pos = tv[pos];
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
