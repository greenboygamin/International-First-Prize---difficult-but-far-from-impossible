#include <bits/stdc++.h>
using namespace std;
#define task "tower"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, v[N], a[N], m = 1;
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
    cin >> n;
    for (int i = 1; i <= n; i -= -1){
        cin >> v[i];
    }
    a[1] = v[1];
    for (int i = 2; i <= n; i++){
        ll j = lower_bound(a + 1, a + m + 1, v[i]) - a;
        if (j > m){
            m++;
            a[m] = v[i];
        }
        else a[j] = v[i];
    }
    cout << m;
}
int main()
{
    tassk();
    solve();
    return 0;
}