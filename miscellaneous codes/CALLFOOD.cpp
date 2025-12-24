#include <bits/stdc++.h>
using namespace std;
#define task "CALLFOOD"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, ab[N], a[N];
pll food[N];
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
    for (int i = 1; i <= n; i++){
        cin >> food[i].second >> food[i].first;
    }
    sort(food + 1, food + n + 1);
    ab[1] = food[1].second - food[1].first;
    for (int i = 2; i <= n; i++){
        ab[i] = min(ab[i - 1], food[i].second - food[i].first);
    }
    a[n] = food[n].second;
    for (int i = n - 1; i >= 1; i--) a[i] = min(a[i + 1], food[i].second);
    ll ans, cost = 0;
    for (int i = 1; i <= n; i++){
        ans = 1e15;
        cost += food[i].first;
        ans = min(ans, cost + ab[i]);
        ans = min(ans, cost - food[i].first + a[i]);
        cout << ans << el;
    }
    //for (int i = 1; i <= k; i++) cout << food[i].a << " " << food[i].b << " " << food[i].c << el;
}
int main()
{
    tassk();
    solve();
    return 0;
}