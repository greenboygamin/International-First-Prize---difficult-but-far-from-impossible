#include <bits/stdc++.h>
using namespace std;
#define task "CHINHHOP"
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
ll n, x[N], z;
bool kt[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void np(int i){
    for (int j = 1; j <= n; j++){
        if (kt[j]) continue;
        x[i] = j;
        kt[j] = 1;
        if (i == z){
            for (int k = 1; k <= z; k++){
                cout << x[k] << " ";
            }
            cout << el;
        }
        else np(i + 1);
        kt[j] = false;
    }
}
void solve() {
    cin >> n >> z;
    np(1);
}

int main() {
    tassk();
    solve();
    return 0;
}