#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CAU 1"
#define vll vector<long long>
const ll N = 1e6 + 7;
ll x, y;
void task(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}
ll gcd(ll a, ll b){
    while (b != 0){
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
void solve(){
    ll dem = 0;
    cin >> x >> y;
    ll ucln = gcd(x, y);
    for (int i = 1; i <= ucln; i++){
        if (ucln % i == 0) dem++;
    }
    cout << dem;
}

int main(){
    task();
    solve();
    return 0;
}