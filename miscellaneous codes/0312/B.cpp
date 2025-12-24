#include <bits/stdc++.h>
using namespace std;
#define task "suaxe"
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
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    ll le = 0;
    for (int i = 0; i < n; i++) {
        ll s, p, e, a;
        cin >> s >> p >> e >> a;
        ll gap = s - le;
        for (int j = 0; j <= i; j++) {
            if (dp[j] != -1) dp[j] += gap;
        }
        for (int j = i; j >= 0; j--) {
            if (dp[j] >= a) {
                dp[j + 1] = max(dp[j + 1], dp[j] - a + e - p);
            }
        }
        le = e;
    }
    int res = 0;
    for (int i = n; i >= 0; i--) {
        if (dp[i] != -1) {
            res = i;
            break;
        }
    }
    cout << res << el;
}

int love_tkiet = 100, love_pi = 0;

void qlai(){
    bool possible = 0;
    if 
}

int main() {
    tassk();
    solve();
    return 0;
}