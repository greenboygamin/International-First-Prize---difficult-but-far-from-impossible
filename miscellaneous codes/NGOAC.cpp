#include <bits/stdc++.h>
using namespace std;
#define task "NGOAC"
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
ll dp[N], l = 0, k = 0;
string s;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> s;
    s = " " + s;
    dp[0] = 0; dp[1] = 0;
    for (int i = 2; i < s.size(); i++){
        if (s[i] == '(') dp[i] = 0;
        if (s[i] == ')'){
            if (s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
            if (s[i - dp[i - 1] - 1] == '(') dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
        }
        l = max(dp[i], l);
    }
    for (int i = 1; i < s.size(); i++) if (dp[i] == l) k++;
    if (l == 0) cout << 0 << " " << 1;
    else cout << l << " " << k;
}
int main() {
    tassk();
    solve();
    return 0;
}