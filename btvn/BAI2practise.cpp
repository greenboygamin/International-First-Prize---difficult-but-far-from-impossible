#include <bits/stdc++.h>
using namespace std;
#define task "BAI2"
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
const int N = 2e5 + 5;
const int MOD = 998244353;

pll booth[N];
ll n, m, last[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void compress(){
    set<ll> s;
    for (int i = 1; i <= n; i++) s.insert(booth[i].first);
    vll b(s.begin(), s.end());
    for (int i = 1; i <= n; i++) booth[i].second = lower_bound(b.begin(), b.end(), booth[i].first) - b.begin() + 1;
}

void Inp(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> booth[i].first;
    compress();
}

ll cnt(ll x){
    return (x * (x + 1) / 2) % MOD;
}

void solve() {
	ll ans = 0, sum = cnt(m);
    for (int i = 1; i <= n; i++){
        if (last[booth[i].second] == 0) sum = (sum + MOD - booth[i].first) % MOD;
        ll l = last[booth[i].second] + 1, r = i - 1;
        if (l <= r) ans = (ans + cnt(r - l + 1) * booth[i].first % MOD) % MOD;
        last[booth[i].second] = i;
    }
    for (int i = 1; i <= n; i++){
        if (last[booth[i].second]){
            ll l = last[booth[i].second] + 1, r = n;
            if (l <= r) ans = (ans + cnt(r - l + 1) * booth[i].first % MOD) % MOD;
            last[booth[i].second] = 0;
        }
    }
    ll tmp = cnt(n);
    sum = (sum * tmp) % MOD;
    ans = (ans + sum) % MOD;
    cout << ans;
}

int main() {
    tassk();
    Inp();
    solve();
    return 0;
}
