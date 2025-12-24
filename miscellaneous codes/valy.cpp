#include <bits/stdc++.h>
using namespace std;
#define task "valy"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 1e9 + 7;
ll n, m, w[N], v[N], dp[N], tv[N], c[N];
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = w[i]; j <= m; ++j){
            if (dp[j] < dp[j - w[i]] + v[i]){
                dp[j] = dp[j - w[i]] + v[i];
                tv[j] = i;
            }
        }
    }
    cout << dp[m] << el;
    ll j = m;
    while (j > 0 && tv[j] > 0){
        c[tv[j]] ++;
        j -= w[tv[j]];
    }
    for (int i = 1; i <= n; i++){
        if (c[i]) cout << i << " " << c[i] << el;
    } 
}
int main()
{
    tassk();
    solve();
    return 0;
}