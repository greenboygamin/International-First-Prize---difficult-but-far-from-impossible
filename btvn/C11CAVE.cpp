#include <bits/stdc++.h>
using namespace std;
#define task "C11CAVE"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, h, a[N], dat[N], tran[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve(){
    cin >> n >> h;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (i % 2 != 0) {
            dat[a[i]]++;
        }
        else {
            tran[h - a[i] + 1]++;
        }
    }
    for (int i = h; i >= 1; i -= 1){
        dat[i] += dat[i + 1];
        
    }
    for (int i = 1; i <= h; i++){
        tran[i] += tran[i - 1];
    }
    
    ll dem = 0, mins = 0x3f3f3f3f;
    for (int i = 1; i <= h; i++){
        ll cur = dat[i] + tran[i];
        if (cur < mins){
            mins = cur;
            dem = 0;
        }
        if (cur == mins) dem++;
    }
    cout << mins << " " << dem;
}   
int main() {
    tassk();
    solve();
    return 0;
}