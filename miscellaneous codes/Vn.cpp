#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("Vn.inp", "r")) {
        freopen("Vn.inp", "r", stdin);
        freopen("Vn.out", "w", stdout);
    }
}
ll gcd(ll a, ll b){
    if (a==0||b==0) return a+b;
    while (a!=b){
        if (a>b){
            a-=b;
        }
        else b-=a;
    }
    return a;
}
void Solve() {
    cin >> n >> m;
    ll ucln = gcd(n,m);
    cout << ucln << '\n' << n/ucln <<" "<< m/ucln;
}
int main() {
    Task();
    Solve();
    return 0;
}