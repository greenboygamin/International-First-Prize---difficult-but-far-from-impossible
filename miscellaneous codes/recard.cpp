#include <bits/stdc++.h>
using namespace std;
#define task "recard"
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
ll n;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    while (cin >> n){
        deque<ll> kiu;
        vll ans;
        for (int i = 1; i <= n; i++) kiu.pb(i);
        while (kiu.size() > 1){
            ans.pb(kiu.front());
            kiu.pop_front();
            kiu.pb(kiu.front());
            kiu.pop_front();
        }
        for (auto i : ans) cout << i << " ";
        cout << el;
        for (auto i : kiu) cout << i << el;
    }
}
int main() {
    tassk();
    solve();
    return 0;
}