#include <bits/stdc++.h>
using namespace std;
#define task "PAIRS"
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
ll n, a[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    stack<ll> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = a[n + 1] = 2e9;
    s.push(0);
    ll dem = 0;
    for (int i = 1; i <= n; i++){
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        if (s.top() != 0) dem++;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; i--){
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        if (s.top() != n + 1 && a[s.top()] != a[i]) dem++;
        s.push(i);
    }
    cout << dem;
}
int main() {
    tassk();
    solve();
    return 0;
}