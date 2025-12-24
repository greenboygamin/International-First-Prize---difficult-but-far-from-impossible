#include <bits/stdc++.h>
using namespace std;
#define task "gifts"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
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
struct stu{
    ll a; ll b; ll c;
} hs[N];
bool ss(const stu &x, const stu &y){
    return x.c < y.c;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> hs[i].a >> hs[i].b;
        hs[i].c = (hs[i].a - hs[i].b);
    }
    sort(hs + 1, hs + n + 1, ss);
    ll sum = 0;
    for (int i = 1; i <= n / 2; i++) sum += hs[i].b;
    for (int i = n / 2 + 1; i <= n; i++) sum += hs[i].a;
    cout << sum;
}
int main()
{
    tassk();
    solve();
    return 0;
}