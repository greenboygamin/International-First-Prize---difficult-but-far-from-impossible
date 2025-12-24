#include <bits/stdc++.h>
using namespace std;
#define task "KPHAN"
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
ll n, k, x[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void np(int i){
    for (int j = 0; j < k; j++){
        x[i] = j;
        if (i == n){
            for (int z = 1; z <= n; z++) cout << x[z];
            cout << el;
        }
        else np(i + 1);
    }
}
void solve() {
    cin >> n >> k;
    np(1);
}

int main() {
    tassk();
    solve();
    return 0;
}