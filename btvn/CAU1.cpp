#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CAU1"
#define vll vector<long long>
const ll N = 1e6 + 7;
ll n, x;
vll c(N);
void task(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        c[x]++;
    }
    ll maxs = *max_element(c.begin(), c.end());
    cout << maxs;
}

int main(){
    task();
    solve();
    return 0;
}