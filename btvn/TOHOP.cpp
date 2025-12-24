#include <bits/stdc++.h>
using namespace std;
#define task "TOHOP"
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
ll n, x[N], k;
bool kt[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void np(int idx, int beg){
    if (idx == k + 1){
        for (int i = 1; i <= k; i++) cout << x[i] << " ";
        cout << el;
        return;
    }
    for (int i = beg; i <= n; i++){
        x[idx] = i;
        np(idx + 1, i + 1);
    }
}
void solve() {
    cin >> n >> k;
    np(1, 1);
}

int main() {
    tassk();
    solve();
    return 0;
}