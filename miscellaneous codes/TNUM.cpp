#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,t,vai;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("TNUM.inp", "r")) {
        freopen("TNUM.inp", "r", stdin);
        freopen("TNUM.out", "w", stdout);
    }
}
bool isprime(int n) {
    if (n<=1) return false;
    if (n<=3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
bool check(ll n) {
    ll dm=sqrt(n);
    return dm*dm==n;
}
void Solve() {
    cin>>n;
    if (check(n)){
        vai=sqrt(n);
        if (isprime(vai)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
}
int main() {
    Task();
    cin>>t; while (t--)
    Solve();
    return 0;
}
