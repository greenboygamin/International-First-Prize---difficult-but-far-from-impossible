#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,maxs;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("GCDMAX.inp", "r")) {
        freopen("GCDMAX.inp", "r", stdin);
        freopen("GCDMAX.out", "w", stdout);
    }
}
void Solve() {
    cin >> n ;
    cout<<n/2<<endl;
}
int main() {
    Task();
    ll t; cin>>t;
    while (t--) Solve();
    return 0;
}