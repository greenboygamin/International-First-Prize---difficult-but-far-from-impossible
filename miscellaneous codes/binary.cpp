#include <bits/stdc++.h>
using namespace std;

#define task "binary"
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

ll n, k;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> k;
    ll kq = 1LL << 60;
    for (int i = k - 1; i <= 60; i++){
        ll res = 0;
        int maxlen = 0, tmp = 1;
        for (int j = i + 1; j <= 60; j++){
            if ((n >> j) & 1LL) res |= (1LL << j);
            else tmp = 0;
            maxlen += tmp;
        }
        int cnt = 0;
        for (int j = i - k + 1; j <= i; j++){
            if ((n >> j) & 1LL) cnt++;
        }
        if (cnt == k){
            cout << n;
            return;
        }
        int extra = k - maxlen;
        int idx = i;
        while (extra > 0){
            extra--;
            res |= (1LL << idx);
            idx--;
        }
        kq = min(kq, res);
    }
    cout << kq;
}


int main() {
    tassk();
    solve();
    return 0;
}   