#include <bits/stdc++.h>
using namespace std;

#define task "collect"
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
const ll N = 1e5 + 5;
const ll M = 2e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e8;

int n, q;
ll m[N], d[N], g[N], pref[N], xuly[N], dp[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> m[i];
    for (int i = 1; i < n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) cin >> g[i];
    ll base = g[1] + g[n];
    for (int i = 1; i < n; i++) base += d[i];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + m[i];
    xuly[0] = 0;
    for (int i = 1; i < n; i++) xuly[i] = g[i] + g[i + 1] - d[i];
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        deque<int> dq; dq.push_back(0);
        dp[0] = 0;
        int ptr = 0;
        for (int i = 1; i <= n; i++) {
            while (ptr < i && pref[i] - pref[ptr] > w) ptr++;
            while (!dq.empty() && dq.front() < ptr) dq.pop_front();
            if (dq.empty()) dp[i] = INF;
            else dp[i] = dp[dq.front()] + xuly[dq.front()];
            if (i < n) {
                ll val = dp[i] + xuly[i];
                while (!dq.empty()) {
                    int back = dq.back();
                    if (dp[back] + xuly[back] >= val) dq.pop_back();
                    else break;
                }
                dq.push_back(i);
            }
        }
        cout << base + dp[n] << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}

