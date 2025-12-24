#include <bits/stdc++.h>
using namespace std;
#define task "ROBOT"
#define ll long long int
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;
const ll MOD = 1e6;
ll n, dp[N], tv[N];
vll v;
struct toado{
    ll x, y, vt;
} diem[N];
bool ss(const toado &a, const toado &b){
    return a.x < b.x;
}
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
        cin >> diem[i].x >> diem[i].y;
        diem[i].vt = i;
    }
    sort(diem + 1, diem + n + 1, ss);
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (diem[i].x > diem[j].x && diem[i].y > diem[j].y){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    tv[diem[i].vt] = diem[j].vt;
                }
            }
        }
    }
    ll maxs = INT_MIN, pos;
    for (int i = 1; i <= n; i++){
        if (dp[i] > maxs){
            maxs = dp[i];
            pos = diem[i].vt;
        }
    }
    cout << maxs << el;
    while (pos > 0){
        v.pb(pos);
        pos = tv[pos];
    }
    reverse(v.begin(), v.end());
    for (auto idx : v) cout << idx << " ";
}
int main()
{
    tassk();
    solve();
    return 0;
}
