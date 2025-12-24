#include <bits/stdc++.h>
using namespace std;
#define task "WEIGHT"
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
    ll len = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; i++){
        dqll dqmin, dqmax;
        for (int j = 1; j <= n; j++){
            while (!dqmin.empty() && dqmin.front() <= j - i) dqmin.pop_front();
            while (!dqmax.empty() && dqmax.front() <= j - i) dqmax.pop_front();
            while (!dqmin.empty() && a[dqmin.back()] >= a[j]) dqmin.pop_back();
            dqmin.pb(j);
            while (!dqmax.empty() && a[dqmax.back()] <= a[j]) dqmax.pop_back();
            dqmax.pb(j);
            if (j >= i) len += a[dqmax.front()] - a[dqmin.front()];
        }
    }
    cout << len;
}

int main() {
    tassk();
    solve();
    return 0;
}
