#include <bits/stdc++.h>
using namespace std;
#define task "sngto"
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
const ll MOD = 2111992;
ll n;
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
bool isprime(ll x){
    ll dem = 0;
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) dem++;
    }
    return dem == 0;
}
void solve(){
    cin >> n;
    queue<pll> kiu;
    ll a[] = {2, 3, 5, 7};
    ll b[] = {1, 3, 7, 9};
    ll ans = 0;
    for (auto i : a) kiu.push({i, 1});
    while (!kiu.empty()){
        ll x = kiu.front().first, k = kiu.front().second;
        kiu.pop();
        if (k == n) ans++;
        else {
            for (auto c : b){
                if (isprime(x * 10 + c)) kiu.push({x * 10 + c, k + 1});
            }
        }
    }
    cout << ans << el;
}
int main()
{
    tassk();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}