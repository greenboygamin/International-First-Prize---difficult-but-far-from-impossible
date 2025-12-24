#include <bits/stdc++.h>
using namespace std;
#define task "DAO"
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
ll n, m, u, v, x[N], y[N], trace[N];
bool a[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void bfs(ll s){
    qll q;
    q.push(s);
    trace[s] = s;
    while (!q.empty()){
        ll i = q.front();
        q.pop();
        for (int j = 1; j <= n; j++){
            if (!trace[j] && a[i][j]){
                q.push(j);
                trace[j] = i;
            }
        }
    }
}
void solve() {
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ll dis = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
            if (dis <= m * m){
                a[i][j] = 1;
                a[j][i] = 1;
            }
        }
    }
    bfs(u);
    ll i = trace[v];
    vll ans;
    while (i != u){
        ans.pb(i);
        i = trace[i];
        if (!trace[i]){
            cout << "-1";
            return;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << el;
    for (auto i : ans) cout << i << " ";
    cout << el;
    //for (int i = 1; i <= n; i++) cout << trace[i] << " ";
}
int main() {
    tassk();
    solve();
    return 0;
}