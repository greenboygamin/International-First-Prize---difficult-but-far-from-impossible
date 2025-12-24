#include <bits/stdc++.h>
using namespace std;

#define task "XOR"
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

const ll N = 3e5 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;
ll a[N];

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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll l = 1, s = 0, x = 0, ans = 0;
    for (int r = 1; r <= n; r++){
        s += a[r]; x ^= a[r];
        while (l < r && s != x){
            s -= a[l];
            x ^= a[l];
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}