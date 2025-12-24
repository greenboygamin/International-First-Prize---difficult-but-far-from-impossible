#include <bits/stdc++.h>
using namespace std;
#define task "fgarden"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, t, h[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dqll dqmin, dqmax;
    ll ans = 0;
    ll l = 1, r = 1;
    dqmin.pb(1); dqmax.pb(1);
    while (r <= n){
        if (h[dqmax.front()] - h[dqmin.front()] <= t){
            ans = max(ans, r - l + 1);
            r++;
            while (!dqmin.empty() && h[dqmin.back()] > h[r]) dqmin.pop_back();
            while (!dqmax.empty() && h[dqmax.back()] < h[r]) dqmax.pop_back();
            dqmin.pb(r); dqmax.pb(r);
        }
        else {
            l++;
            while (!dqmin.empty() && dqmin.front() < l) dqmin.pop_front();
            while (!dqmax.empty() && dqmax.front() < l) dqmax.pop_front();
        }
    }
    cout << ans;
}
int main() {
    tassk();
    solve();
    return 0;
}