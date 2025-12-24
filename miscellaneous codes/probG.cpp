#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll n, a[N], pref[N], suf[N];

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
    pref[0] = 0LL;
    suf[n + 1] = 0LL;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
    ll diff = INF, pos;
    //for (int i = 1; i <= n; i++) cout << pref[i] << " " << suf[i] << el;
    for (int i = 1; i <= n; i++){
        if (abs(pref[i] - suf[i + 1]) < diff){
            diff = abs(pref[i] - suf[i + 1]);
            pos = i;
        }
    }
    cout << pos << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
