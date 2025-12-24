#include <bits/stdc++.h>
using namespace std;
#define task "circle"
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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

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
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; ++i) cin >> w[i];
    vector<bool> is_tgt(n + 1, false);
    ll tot_w = 0;
    for(int i = 0; i < k; ++i) {
        int id; cin >> id;
        is_tgt[id] = true;
        tot_w += w[id];
    }
    
    vector<ll> a(2 * n + 1);
    for(int i = 1; i <= n; ++i) {
        if(is_tgt[i]) a[i] = w[i];
        else a[i] = -w[i];
        a[i + n] = a[i];
    }
    
    vector<ll> p(2 * n + 1, 0);
    for(int i = 1; i <= 2 * n; ++i) p[i] = p[i - 1] + a[i];
    ll max_p = 0;
    deque<int> dq;
    dq.pb(0);
    
    for(int i = 1; i <= 2 * n; ++i) {
        while(!dq.empty() && dq.front() < i - n) dq.pop_front();
        if(!dq.empty()) max_p = max(max_p, p[i] - p[dq.front()]);
        while(!dq.empty() && p[dq.back()] >= p[i]) dq.pop_back();
        dq.push_back(i);
    }
    
    cout << tot_w - max_p << el;
}

int main() {
    tassk();
    solve();
    return 0;
}