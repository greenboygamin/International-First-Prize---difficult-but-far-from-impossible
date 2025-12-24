#include <bits/stdc++.h>
using namespace std;

#define task "CHONDT"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 2e3 + 7;
const ll B = 505;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

ll n;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n;
    vector<ll> X(n), Y(n);
    for (int i = 1; i <= n; i++){
        cin >> X[i] >> Y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll x = X[n/2];
    ll y = Y[n/2];
    cout << x << " " << y << el;
}



int main() {
    tassk();
    solve();
    return 0;
}
