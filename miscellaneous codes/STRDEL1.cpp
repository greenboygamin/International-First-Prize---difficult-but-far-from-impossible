#include <bits/stdc++.h>
using namespace std;
#define task "STRDEL"
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
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void solve() {
    string s; cin >> s;
    stack<char> sta;
    for (char c : s) {
        if (!sta.empty() && ((sta.top() == 'A' && c == 'B') || (sta.top() == 'B' && c == 'B'))) {
            sta.pop();
        } else {
            sta.push(c);
        }
    }
    cout << sta.size() << el;
}

int main() {
    tassk();
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
