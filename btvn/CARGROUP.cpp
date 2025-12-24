#include <bits/stdc++.h>
using namespace std;
#define task "CARGROUP"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
#define ld long double
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, p, l, w[N], v[N], vmin, tl, tv[N];
ld dp[N];
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
    cin >> n >> p >> l;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    v[0] = 1e9;
    for (int i = 1; i <= n; i++){
        tl = 0; vmin = 1e9; dp[i] = 1e9;
        for (int j = i; j >= 1; j--){
            if (tl + w[j] <= p){
                tl += w[j];
                vmin = min(vmin, v[j]);
                if (dp[i] > dp[j - 1] + float(l) / float(vmin)){
                    dp[i] = dp[j - 1] + float(l) / float(vmin);
                    tv[i] = j - 1;
                }
            }
            else break;
        }
    }
    cout << fixed << setprecision(2) << dp[n] << el;
    ll i = n; vll ans;
    while (i > 0){
        ans.pb(i);
        i = tv[i];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
