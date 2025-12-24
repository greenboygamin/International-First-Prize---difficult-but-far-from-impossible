#include <bits/stdc++.h>
using namespace std;
#define task "RGAME"
#define ll long long
#define pb push_back
#define el "\n"
#define vll vector<long long>
const ll N = 3e6 + 2;
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
void solve(){
    ll n, x;
    cin >> n;
    unordered_map<ll, int> mp;
    for (int i = 1; i <= n; i++){
        cin >> x;
        mp[x]++;
    }
    ll max1 = 1, max2 = -1, ans = -1;
    for (auto [len, freq] : mp){
        if (freq >= 4) ans = max(ans, len * len);
    }
    for (auto [len, freq] : mp){
        if (freq >= 2) max1 = max(max1, len);
    }
    for (auto [len, freq] : mp){
        if (freq >= 2 && len < max1) max2 = max(max2, len);
    }
    ans = max(ans, max1 * max2);
    cout << ans << el;
}
int main()
{
    tassk();
    ll k; cin >> k;
    while(k--) solve();
    return 0;
}
