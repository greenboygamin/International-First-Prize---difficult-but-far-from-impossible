#include <bits/stdc++.h>
using namespace std;
#define task "TIMES"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, m;
struct bro{
    ll gt, vt;
} a[N];
vll tmp[N];
priority_queue<pii, vector<pii>, greater<pii>> kiu;
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
bool ss(const bro &x, const bro &y){
    return x.gt > y.gt;
}
void solve( ){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i].gt;
        a[i].vt = i;
    }
    sort(a + 1, a + n + 1, ss);
    for (int i = 1; i <= m; i++){
        tmp[i].pb(a[i].vt);
        kiu.push({a[i].gt, i});
    }
    ll ans = a[1].gt;
    for (int i = m + 1; i <= n; i++){
        pair<ll, ll> p = kiu.top();
        kiu.pop();
        ans = max(ans, p.first + a[i].gt);
        kiu.push({p.first + a[i].gt, p.second});
        tmp[p.second].pb(a[i].vt);
    }
    cout << ans << el;
    for (int i = 1; i <= m; i++){
        for (auto x : tmp[i]) cout << x << " ";
        cout << el;
    }
}
int main()
{
    tassk();
    solve();
    return 0;
}