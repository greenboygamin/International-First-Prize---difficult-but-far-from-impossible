#include <bits/stdc++.h>
using namespace std;
#define task "bando"
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
ll n, m, s, k, w;
ll a[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve() {
    cin >> n >> s >> k;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) a[i][j] = 0;
            else if (a[i][j] == 0) a[i][j] = 1e9;
        }
    }
    
    for (int z = 1; z <= n; ++z){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (a[i][z] > 0 && a[z][j] > 0){
                    a[i][j] = min(a[i][j], a[i][z] + a[z][j]);
                }
            }
        }
    }
    
    for (int z = 1; z <= k; z++){
        cin >> w;
        if (a[s][w] == 0 || a[s][w] == 1e9) cout << -1 << el;
        else cout << a[s][w] << el;
    }
    
}

int main() {
    tassk();
    solve();
    return 0;
}