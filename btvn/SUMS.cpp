#include <bits/stdc++.h>
using namespace std;
#define task "SUMS"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
ll n, a[N], dp[N], s, tv[N];
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
    cin >> n >> s;
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = sum; j >= a[i]; j--){
            if (dp[j - a[i]]){
                dp[j] = 1;
                if (tv[j] == 0) tv[j] = i;
            }
        }
    }
    ll t = s;
    if (!dp[s]){
        cout << "NO";
    }
    else {
        cout << "YES" << el;
            while (t > 0){
            v.pb(tv[t]);
            t -= a[tv[t]];
        }
    }
    reverse(v.begin(), v.end());
    for (auto i : v) cout << i << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
