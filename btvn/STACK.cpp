#include <bits/stdc++.h>
using namespace std;
#define task "STACK"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, a[N], pre[N], nex[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    stack<int> sta;
    sta.push(0);
    a[0] = a[n + 1] = -1e9;
    for (int i = 1; i <= n; i++){
        while (!sta.empty() && a[sta.top()] >= a[i]){
            sta.pop();
        }
        pre[i] = sta.top();
        sta.push(i);
    }
    while (!sta.empty()) sta.pop();
    sta.push(n + 1);
    for (int i = n; i >= 1; i--){
        while (!sta.empty() && a[sta.top()] >= a[i]){
            sta.pop();
        }
        nex[i] = sta.top();
        sta.push(i);
    }
    for (int i = 1; i <= n; i++) cout << pre[i] + 1 << " ";
    cout << el;
    for (int i = 1; i <= n; i++) cout << nex[i] - 1 << " ";
}

int main() {
    tassk();
    solve();
    return 0;
}
