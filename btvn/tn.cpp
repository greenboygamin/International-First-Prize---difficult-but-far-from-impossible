#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[100007];
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("tn.inp", "r")) {
        freopen("tn.inp", "r", stdin);
        freopen("tn.out", "w", stdout);
    }
}
int main() {
    Task();
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll res = a[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, a[i]);
    }
    cout << res << "\n";
    for (int i = 0; i < n; i++) {
        cout << res / a[i] << " ";
    }
    return 0;
}
