#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define fileName "KT"
#define pb push_back
const int N = 1e6+7;
int n, a[N], s = 0, vt[N];
vector<int> ans, ans2;
bool f[N], kt[N];
void Start(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(fileName".inp","r")){
        freopen(fileName".inp","r",stdin);
        freopen(fileName".out","w",stdout);
    }
}
void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = s / 2 - a[i]; j >= 0; j--){
            if (f[j] && f[j + a[i]] == 0){
                f[j + a[i]] = 1;
                vt[j + a[i]] = i;
            }
        }
    }
    ll i1 = s / 2;
    while (f[i1] == 0) i1--;
    ll i2 = i1;
    cout << s - i1 * 2 << el;
    while (i1 > 0){
        kt[vt[i1]] = 1;
        cout << a[vt[i1]] << " ";
        i1 = i1 - a[vt[i1]];
    }
    cout << el;
    for (int i = 1; i <= n; i++){
        if (!kt[i]) cout << a[i] << " ";
    }
    cout << el;
    cout << i2 << " " << s - i2;
}
int main(){
    Start();
    Solve();
    return 0;
}