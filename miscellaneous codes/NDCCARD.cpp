#include <bits/stdc++.h>
using namespace std;
#define task "NDCCARD"
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
ll n, m, a[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve(){
    cin >> n >> m;
    ll s = 0, l, r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll maxs = -1e9;
    for (int i = 1; i <= n - 2; i++){
        l = i + 1; r = n;
        while (l <= r){
            s = a[i] + a[l] + a[r];
            if (s <= m) l++;
            else r--;
        }
        maxs = max(maxs, s);
    }
    cout << maxs;
}   
int main() {
    tassk();
    solve();
    return 0;
}