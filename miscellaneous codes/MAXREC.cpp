#include <bits/stdc++.h>
using namespace std;
#define task "WATER"
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
ll n, m, a[M][M];
vll h(N);
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    ll maxs = 0, wid, tmp;
    for (int i = 1; i <= m; i++){
        tmp = 0;
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 0) h[j] = 0;
            else h[j]++;
        }
        stack<int> s;
        for (int z = 1; z <= h.size(); z++){
            while (!s.empty() && h[s.top()] > h[z]){
                ll hei = h[s.top()];
                s.pop();
                if (s.empty()) wid = i - 1;
                else wid = i - s.top() - 1;
                tmp = max(tmp, wid * hei);
            }
            s.push(z);
        }
        maxs = max(maxs, tmp);
    }
    cout << maxs;
}
int main() {
    tassk();
    solve();
    return 0;
}