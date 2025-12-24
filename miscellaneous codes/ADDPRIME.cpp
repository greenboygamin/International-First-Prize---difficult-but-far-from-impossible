#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define pb push_back
const ll SIZE=1e6+7;
const ll DAMN=1e9+7;
ll f[SIZE]; bool isprime[SIZE];
void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("ADDPRIME.inp", "r")) {
        freopen("ADDPRIME.inp", "r", stdin);
        freopen("ADDPRIME.out", "w", stdout);
    }
}
void Solve(){
    ll n;
    cin>>n;
    fill(isprime, isprime + n + 1, 1);
    vector<ll> primes;
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= n; i++){
        if (isprime[i]){
            for (int j = i * i; j <= n; j += i){
                isprime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (isprime[i]) primes.pb(i);
    }
    f[0] = 1;
    for (int i = 0; i < primes.size(); i++){
        for (int j = primes[i]; j <= n; j++){
            if (f[j - primes[i]] > 0) f[j] = (f[j] % DAMN + f[j - primes[i]] % DAMN) % DAMN;
        }
    }
    cout << f[n] << " ";
}   
int main() {
    Task();
    Solve();
    return 0;
}

