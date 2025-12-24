#include <bits/stdc++.h>
using namespace std;

#define task "windows"
#define el "\n"
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

ll n;
vll adj[N];
vll ans;
struct windows{
    int x1, x2, y1, y2, x3, y3;
} cell[N];
bool visited[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool check(windows a, windows b){
    return (a.x1 <= b.x3 && a.y1 <= b.y3 && a.x2 >= b.x3 && a.y2 >= b.y3);
}

void bfs(int u){
    ans.pb(u);
    visited[u] = 1;
    for (auto v : adj[u]){
        if (!visited[v]){
            bfs(v);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> cell[i].x1 >> cell[i].y1 >> cell[i].x2 >> cell[i].y2;
        cell[i].x3 = cell[i].x2;
        cell[i].y3 = cell[i].y1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j){
                if (check(cell[j], cell[i])){
                    adj[i].pb(j);
                }
            }
        }
    }
    bfs(1);
    cout << ans.size() << el;
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 