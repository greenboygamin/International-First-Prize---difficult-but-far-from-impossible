#include <bits/stdc++.h>
using namespace std;

#define task "LOADBALANCING"
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
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

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
    ll s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        if (i <= n - s % n) ans += abs(a[i] - s / n);
        else ans += abs(a[i] - (s / n + 1));
    }
    cout << ans / 2;
}

int main() {
    tassk();
    solve();
    return 0;
}