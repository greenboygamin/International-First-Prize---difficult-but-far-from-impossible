#include <bits/stdc++.h>
using namespace std;
#define task "DANCING"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, x, dem = 0;
vll a1, a2, b1, b2;
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
        if (x > 0) a1.pb(x);
        else a2.pb(abs(x));
    }
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x > 0) b1.pb(x);
        else b2.pb(abs(x));
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());
    ll p = -1; ll j;
    for (auto x : a1){
        j = upper_bound(b2.begin() + p + 1, b2.end(), x) - b2.begin();
        if (j >= b2.size()) break;
        dem++;
        p = j;
    }
    p = -1;
    for (auto x : b1){
        j = upper_bound(a2.begin() + p + 1, a2.end(), x) - a2.begin();
        if (j >= a2.size()) break;
        dem++;
        p = j;
    }
    cout << dem;
}
int main()
{
    tassk();
    solve();
    return 0;
}