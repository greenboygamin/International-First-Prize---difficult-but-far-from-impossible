#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n; string s;
void Task() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    if (fopen("CPRIME.inp", "r")) {
        freopen("CPRIME.inp", "r", stdin);
        freopen("CPRIME.out", "w", stdout);
    }
}
bool isprime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
void Solve() {
    cin>>n;
    s=to_string(n);
    reverse(s.begin(),s.end());
    ll rev=stoll(s);
    if (isprime(n)&&isprime(rev)) cout<<1;
    else cout<<0;
    
}
int main(){
    Task();
    Solve();
    return 0;
}
