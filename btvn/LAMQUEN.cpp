#include <bits/stdc++.h>
using namespace std;
#define task "LAMQUEN"
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
bool a[M][M], visited[N];
int maxs = 0;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void dfs(int u, int &size){
    visited[u] = 1;
    size++;
    for (int v = 1; v <= n; v++){
        if (!visited[v] && a[u][v]){
            dfs(v,size);
        }
    }
}
void connected(){
    ll dem = 0;
    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            int size = 0;
            dfs(i, size);
            maxs = max(maxs, size);
            ++dem;
        }
    }
    cout << dem << el;
    cout << maxs;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c;
            cin >> c;
            a[i][j] = (c == '1');
        }
    }
    connected();
}

int main() {
    tassk();
    solve();
    return 0;
}
