#include <bits/stdc++.h>
using namespace std;

#define task "maxsegment"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

ll n, k, a[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    int delta;
    cin >> delta >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    deque<pll> dq;
    for (int i = 1; i < k; i++){
        while (!dq.empty() && dq.back().first < a[i]) dq.pop_back();
        dq.pb({a[i], i});
    }
    for (int i = k; i <= n; i++){
        while (!dq.empty() && dq.back().first < a[i]) dq.pop_back();
        dq.pb({a[i], i});
        while (!dq.empty() && dq.front().second <= i - k) dq.pop_front();
        cout << dq.front().first << " ";
    }
}


int main() {
    tassk();
    solve();
    return 0;
}   