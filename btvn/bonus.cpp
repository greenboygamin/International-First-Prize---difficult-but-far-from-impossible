#include <bits/stdc++.h>
using namespace std;
#define task "bonus"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
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
map<pii, ll> mp;
ll n, k, ans = INT_MIN;
struct qua{
    ll x, y, c;
};
qua a[N];
bool insize(ll u, ll v){
    return (1 <= u && u <= n && 1 <= v && v <= n);
}
int tx[] = {2,2,1,-1,-2,-2,-1,1};
int ty[] = {-1,1,2,2,1,-1,-2,-2};
void solve() {
    cin >> n >> k;
    for (int x, y, c, i = 1; i <= k; i++){
        cin >> x >> y >> c;
        mp[{x, y}] += c;
        a[i] = {x, y, c};
    }
    for (int i = 1; i <= k; i++){
        int u = a[i].x, v = a[i].y;
        for (int j = 0; j < 7; j++){
            if (insize(u + tx[j], v + ty[j]) && mp.find({u + tx[j], v + ty[j]}) == mp.end()){
                int x = u + tx[j], y = v + ty[j];
                ll sum = 0;
                for (int l = 0; l < 7; l++){
                    if (insize(x + tx[l], y + ty[l]) && mp.find({x + tx[l], y + ty[l]}) != mp.end()){
                        sum += mp[{x + tx[l], y + ty[l]}] * 1LL;
                    }
                ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans;
}
int main()
{
    tassk();
    solve();
    return 0;
}