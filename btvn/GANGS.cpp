#include <bits/stdc++.h>
using namespace std;
#define task "GANGS"
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
const ll M = 1e4 + 2;
const ll MOD = 2111992;
ll p, q, n, m;
vll f[N];
vll e[N];
vll gang[N];
char c;
bool visited[M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void bfs(ll u){
    qll q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty()){
        ll x = q.front();
        q.pop();
        for (auto y : gang[x]){
            if (!visited[y]){
                q.push(y);
                visited[y] = 1;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> c >> p >> q;
        if (c == 'F'){
            f[p].pb(q);
            f[q].pb(p);
        }
        else if (c == 'E'){
            e[p].pb(q);
            e[q].pb(p);
        }
    }
    for (int i = 1; i <= n; i++){
        for (auto j : f[i]){
            gang[i].pb(j);
        }
        for (auto j : e[i]){
            for (auto k : e[j]){
                if (i != k){
                    gang[i].pb(k);
                }
            }
        }
    }
    ll dem = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dem++;
            bfs(i);
            
        }
    }
    cout << dem;
}
int main() {
    tassk();
    solve();
    return 0;
}