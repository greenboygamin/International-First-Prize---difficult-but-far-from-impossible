#include <bits/stdc++.h>
using namespace std;
#define task "EXPEDI"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
ll n, p, l;
priority_queue<ll> kiu;
struct xe{
    ll fuel, dis;
} a[N];
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
bool ss(const xe &x, const xe &y){
    return x.dis < y.dis;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].dis >> a[i].fuel;
    cin >> l >> p;
    a[0].dis = 0; a[n + 1].dis = l;
    for (int i = 1; i <= n; i++){
        a[i].dis = l - a[i].dis;
    }
    sort(a + 1, a + n + 1, ss);
    a[0].dis = 0; a[n + 1].dis = l;
    ll ans = 0;
    for (int i = 0; i <= n; i++){
        if (p >= a[i + 1].dis - a[i].dis){
            p -= a[i + 1].dis - a[i].dis;
            kiu.push(a[i + 1].fuel);
        }
        else {
            while(!kiu.empty() && p < a[i + 1].dis - a[i].dis){
                ll k = kiu.top();
                kiu.pop();
                p = p + k;
                ans++;
            }
            if (kiu.empty() && p < a[i + 1].dis - a[i].dis){
                cout << -1;
                return;
            }
            p -= a[i + 1].dis - a[i].dis;
            kiu.push(a[i + 1].fuel);
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