#include <bits/stdc++.h>
using namespace std;
#define task "NKSGAME"
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
const ll INF = 1e9 + 7;
const ll MOD = 2111992;
ll n, b[N], c[N];
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
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1, greater<ll>());
    ll mins = INF, i = 1, j = 1;
    while (i <= n && j <= n){
        ll tmp = b[i] + c[j];
        mins = min(mins, abs(tmp));
        if (tmp < 0) i++;
        else j++;
    }
    cout << mins;
}   
int main() {
    tassk();
    solve();
    return 0;
}