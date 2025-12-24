#include <bits/stdc++.h>
using namespace std;
#define task "FLOWER"
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
ll w, h, n, k, x[M], y[M];
ll px[] = {0, 0, 1, -1};
ll py[] = {1, -1, 0, 0};
bool visited[M][M];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
vector<vll> bfs(){
    queue<pll> q;
    vector<vll> a (w + 1, vll(h + 1, 0));
    for (int idx = 1; idx <= n; idx++){
        a[x[idx]][y[idx]] = k;
        q.push({x[idx], y[idx]});
    }
    while (!q.empty()){
        ll cx = q.front().first;
        ll cy = q.front().second;
        q.pop();
        for (int z = 0; z < 4; z++){
            ll nx = cx + px[z];
            ll ny = cy + py[z];
            if (1 <= nx && nx <= w && 1 <= ny && ny <= h){
                ll tmp = max(0LL, a[cx][cy] - 1);
                if (a[nx][ny] < tmp){
                    a[nx][ny] = tmp;
                    q.push({nx, ny});
                }
            }
        }
    }
    return a;
}
void solve() {
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    cin >> w >> h >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    auto a = bfs();
    ll mins = 1e9;
    for (int i = 1; i <= w; ++i){
        for (int j = 1; j <= h; ++j){
            mins = min(mins, a[i][j]);
        }
    }
    cout << mins;

}
int main() {
    tassk();
    solve();
    return 0;
}