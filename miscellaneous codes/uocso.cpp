#include <bits/stdc++.h>
using namespace std;
#define task "uocso"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pqll priority_queue
const ll N = 1e6 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e5;
ll a, b, a1, b1, c[N];
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
    cin >> a >> b;
    a1 = b1 = 1;
    memset(c, 0, sizeof c);
    for (int i = 2; i <= sqrt(a); i++){
        while (a % i == 0){
            c[i]++;
            a /= i;
        } 
    }
    if (a > 1){
        if (a > 1e5) a1 = a;
        else c[a]++;
    }
    for (int i = 2; i <= sqrt(b); i++){
        while (b % i == 0){
            c[i]++;
            b /= i;
        } 
    }
    if (b > 1){
        if (b > 1e5) b1 = b;
        else c[b]++;
    }
    ll ans = 1;
    for (int i = 2; i <= INF; i++){
        ans *= (c[i] + 1);
    }
    if (a1 > 1 && b1 > 1){
        if (a1 == b1) ans *= 3;
        else ans *= 4;
    }
    else if (a1 > 1 && b1 == 1) ans *= 2;
    else if (a1 == 1 && b1 > 1) ans *= 2;
    cout << ans << el;
}
int main()
{
    tassk();
    ll t; cin >> t; while(t--)
    solve();
    return 0;
}