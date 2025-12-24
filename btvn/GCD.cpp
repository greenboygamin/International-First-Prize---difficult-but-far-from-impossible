#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,maxs;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("GCD.inp", "r")) {
        freopen("GCD.inp", "r", stdin);
        freopen("GCD.out", "w", stdout);
    }
}
void Solve() {
    cin >> n ;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    for (int i=v.size()-1; i>0; i--){
        for (int j=i-1; j>=0; j--){
            maxs=max(__gcd(v[i],v[j]),maxs);
            if (maxs>v[j]) break;
        }
    }
    cout<<maxs;
}
int main() {
    Task();
    Solve();
    return 0;
}