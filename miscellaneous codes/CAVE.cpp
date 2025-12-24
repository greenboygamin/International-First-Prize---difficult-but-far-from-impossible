#include <bits/stdc++.h>
using namespace std;

#define task "CAVE"
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
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

ll n, h, dat[N], tran[N], height[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        if (i % 2 != 0){
            dat[tmp]++;
        }
        else {
            tran[h - tmp + 1]++;
        }
    }
    ll mins = INF, dem = 0;
    
    for (int i = h; i >= 1; i--){
        dat[i] += dat[i + 1];
    }

    for (int i = 1; i <= h; i++){
        tran[i] += tran[i - 1];
    }
    for (int i = 1; i <= h; i++){
        if (tran[i] + dat[i] < mins){
            mins = tran[i] + dat[i];
        }
    }
    for (int i = 1; i <= h; i++){
        if (tran[i] + dat[i] == mins){
            dem++;
        }
    }
    cout << mins << " " << dem << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
 