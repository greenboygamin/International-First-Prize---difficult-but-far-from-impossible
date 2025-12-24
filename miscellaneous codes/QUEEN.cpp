#include <bits/stdc++.h>
using namespace std;
#define task "queen"
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
ll n, col[N], diag1[N], diag2[N], board[N];
vector<vll> sol;
bool kt[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void np(int row){
    if (row == n + 1){
        vll sols;
        for (int i = 1; i <= n; i++) sols.pb(board[i]);
        sol.pb(sols);
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!col[i] && !diag1[row - i + n] && !diag2[i + row]){
            col[i] = diag1[row - i + n] = diag2[row + i] = 1;
            board[row] = i;
            np(row + 1);
            col[i] = diag1[row - i + n] = diag2[row + i] = 0;
        }
    }
}
void solve() {
    cin >> n;
    np(1);
    for (auto i : sol){
        for (auto j : i){
            cout << j << " ";
        }
        cout << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}