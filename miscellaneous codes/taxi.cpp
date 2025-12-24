#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define fileName "taxi"
#define pb push_back
#define vll vector<long long>
const ll N = 1e6+7;
ll n, ans, c1 = 0, c2 = 0, c3 = 0, c4 = 0, dem = 0;
void Start(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(fileName".inp","r")){
        freopen(fileName".inp","r",stdin);
        freopen(fileName".out","w",stdout);
    }
}
void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> ans;
        if (ans == 1) c1++;
        if (ans == 2) c2++;
        if (ans == 3) c3++;
        if (ans == 4) c4++;
    }
    dem += c4 + c2 / 2 + c3;
    if (c3 < c1) c1 -= c3;
    else c1 = 0;
    c2 %= 2;
    if (c2 == 1){
        dem++;
        if (c1 > 2){
            c1 -= 2;
            dem += c1 / 4;
            if (c1 % 4 != 0) dem++;
        }
    }
    else {
        dem += c1 / 4;
        if (c1 % 4 != 0) dem++;
    }
    cout << dem;
}
int main(){
    Start();
    Solve();
    return 0;
}