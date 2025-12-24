#include <bits/stdc++.h>
using namespace std;
#define task "MSTICK"
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
ll n;
struct stick{
    ll l, r;
};
bool ss(const stick &x, const stick &y){
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;

}
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
    stick a[n + 2];
    for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1, ss);
    ll dp[n];
    // dp[i] : so phut can de chit tai object i
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = 1e9;
        for (int j = 1; j < i; j++){
            if (a[i].l >= a[j].l && a[i].r >= a[j].r){
                dp[i] = min(dp[i], dp[j]);
            }
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[n] << el;
}   
int main() {
    tassk();
    ll t; cin >> t;
    while (t--)
    solve();
    return 0;
}