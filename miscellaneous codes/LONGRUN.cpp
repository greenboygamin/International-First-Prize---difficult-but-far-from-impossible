#include <bits/stdc++.h>
using namespace std;

#define task "LONGRUN"
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
ll n, l, c, a[N], dem = 0, pn[N];
ld pbu[N];
ld x[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> l >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ld t = ((ld) c * (ld) l) / (ld) a[n];
    x[n] = l;
    for (int i = 1; i <= n - 1; i++){
        x[i] = ((ld) a[i] * t) / c;
    }
    pn[n] = l, pbu[n] = 0;
    for (int i = 1; i <= n - 1; i++){
        pn[i] = floor(x[i]);
        pbu[i] = x[i] - (ld) pn[i];
    }
    //for (int i = 1; i <= n; i++) cout << pn[i] << " ";
    //cout << el;
    //for (int i = 1; i <= n; i++) cout << pbu[i] << " ";
    ll dem = 0;
    //for (int i = 1; i <= n; i++) cout << x[i] << " ";
    //cout << el;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            dem += (x[i] - x[j]);
        }
    }
    cout << dem;
}

int main() {
    tassk();
    solve();
    return 0;
}

/*

*/