
#include <bits/stdc++.h>
using namespace std;

#define task "MININTERVAL"
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    ll a, b; cin >> a >> b;
    vector<string> ans;
    while (a != b){
        while (a % 2 == 0){
            a /= 2;
            ans.pb("B+=B");
        }
        while (b % 2 == 0){
            b /= 2;
            ans.pb("A+=A");
        }
        if (a == b) break;
        if (b > a){
            b += a;
            ans.pb("B+=A");
        }
        if (a > b){
            a += b;
            ans.pb("A+=B");
        }
    }
    cout << ans.size() << el;
    for (string s : ans) cout << s << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
