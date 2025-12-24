#include <bits/stdc++.h>
using namespace std;
#define task "SUSHI"
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
const ll INF = 1e9 + 7;
ll n, t[N];

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
    for (int i = 1; i <= n; i++) cin >> t[i];
    //dp[i]: do dai cua phan doan hop le lon nhat tinh toi i
    ll dem = 0;
    vll segg;
    for (int i = 2; i <= n; i++){
        if (t[i] == t[i - 1]) dem++;
        else {
            segg.pb(dem);
            dem = 1;
        }
    }
    segg.pb(dem);
    ll maxs = -INF;
    for (int i = 1; i < segg.size(); i++){
        maxs = max(maxs, 2 * min(segg[i - 1], segg[i]));
    }
    cout << maxs;
}   
int main() {
    tassk();
    solve();
    return 0;
}