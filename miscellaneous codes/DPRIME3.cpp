#include <bits/stdc++.h>
using namespace std;
#define task "DPRIME3"
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
ll n, x, y, z;
vector<bool> f(N, 1);
vll primes;
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
bool check(ll x){
    for (auto i : primes){
        if (i >= x)  break;
        if (x % i == 0) return false;
    }
    return true;
}
void solve() {
    f[0] = f[1] = 0;
    cin >> n;
    for (int i = 2; i <= sqrt(N); i++){
        if (f[i]){
            for (int j = i * i; j <= N; j += i){
                f[j] = 0;
            }
        }
    }
    for (int i = 3; i <= N; i++){
        if (f[i]) primes.pb(i);
    }
    ll dem = 0;
    for (int y = 0; primes[y] * primes[y] + 4 <= n && y < primes.size(); y++){
            z = primes[y] * primes[y] + 4;
            if (check(z)){
                cout << 2 << " " << primes[y] << " " << z << el;
                dem++;
            }
    }
    if (dem == 0) cout << -1;
}
int main()
{
    tassk();
    solve();
    return 0;
}