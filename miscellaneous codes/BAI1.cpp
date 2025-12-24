#include <bits/stdc++.h>
using namespace std;
#define task "BAI1"
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
const ll MOD = 666013;
const ll INF = 1e9 + 7;
ll n, a[N], q, u, v;
ll c[N], m[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> u >> v;
    ll sum = c[v] - c[u - 1];
    ll mul = m[v] - m[u - 1];
    ll ans = sum * sum - mul;
    ans /= 2;
    cout << ans << el;
}   

int main() {
    tassk();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        c[i] = c[i - 1] + a[i];
        m[i] = m[i - 1] + a[i] * a[i];
    }
    while (q--)
    solve();
    return 0;
}