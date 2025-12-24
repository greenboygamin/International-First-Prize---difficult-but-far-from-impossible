#include <bits/stdc++.h>
using namespace std;
#define task "sumlr"
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
ll n, l, r, a[N], prf[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }
    deque<pll> kiu;
    ll maxs = LLONG_MIN;
    for (int i = l; i <= n; i++){
        if (i > r){
            while (!kiu.empty() && kiu.front().second < i - r) kiu.pop_front();
        }
        while (!kiu.empty() && kiu.back().first >= prf[i - l]) kiu.pop_back();
        kiu.push_back({prf[i - l], i - l});
        maxs = max(maxs, prf[i] - kiu.front().first);
    }
    cout << maxs;
}
int main() {
    tassk();
    solve();
    return 0;
}