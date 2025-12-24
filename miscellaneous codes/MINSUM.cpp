#include <bits/stdc++.h>
using namespace std;
#define task "MINSUM"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll g, r;
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
    cin >> g >> r;
    if (r % g != 0) cout << -1;
    else {
        ll maxs = INT_MAX;
        ll k = r / g;
        for (int x = 1; x <= k; x++){
            if (k % x == 0){
                ll y = k / x;
                if (gcd(x, y) == 1){
                    maxs = min(maxs, g*(x + y));
                }
            }
        }
        cout << maxs;
    }
}
int main()
{
    tassk();
    solve();
    return 0;
}