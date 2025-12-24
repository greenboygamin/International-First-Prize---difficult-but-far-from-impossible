#include <bits/stdc++.h>
using namespace std;
#define task "MTWALK"
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
const ll INF = 1e9 + 7;
const ll MOD = 2111992;
ll n, a[M][M];
bool visited[M][M];
ll px[] = {-1, 1, 0, 0};
ll py[] = {0, 0, -1 ,1};
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
struct node{
    ll x, y, mins, maxs;
};
struct ss{
    bool operator()(const node &a, const node &b){
        return a.maxs - a.mins > b.maxs - b.mins;
    }
};
ll dijkstra(){
    pq<node, vector<node>, ss> kiu;
    kiu.push({1, 1, a[1][1], a[1][1]});
    visited[1][1] = 1;
    while (!kiu.empty()){
        node cur = kiu.top();
        kiu.pop();
        ll cx = cur.x, cy = cur.y;
        ll cmins = cur.mins, cmaxs = cur.maxs;
        if (cx == n && cy == n) return cmaxs - cmins;
        for (int i = 0; i < 4; i++){
            ll nx = cx + px[i];
            ll ny = cy + py[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !visited[nx][ny]){
                visited[nx][ny] = 1;
                kiu.push({nx, ny, min(cmins, a[nx][ny]), max(cmaxs, a[nx][ny])});
            }
        }
    }
    return -1;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    cout << dijkstra() << el;
}   
int main() {
    tassk();
    solve();
    return 0;
}