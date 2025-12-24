#include <bits/stdc++.h>
using namespace std;

#define task "SPELL"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
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

ll n, m, k, dp[Z][Z][Z], dist[N];
ll px[] = {-1, 1, 0, 0};
ll py[] = {0, 0, -1, 1};
string s;
char a[M][M];
bool visited[M][M];
struct state{
    ll x, y, p;
    state(ll _x = 0, ll _y = 0, ll _p = 0){
        x = _x; y = _y; p = _p;
    }
};

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> m >> n >> k >> s;
    s = " " + s;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    queue<state> q;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j][0] = 0;
            q.push(state(i, j, 0));
        }
    }
    while (!q.empty()){
        ll x = q.front().x;
        ll y = q.front().y;
        ll p = q.front().p;
        q.pop();
        if (p == k){
            cout << dp[x][y][p] << el;
            return;
        }
        for (int i = 0; i < 4; i++){
            ll nx = x + px[i];
            ll ny = y + py[i];
            if (1 <= nx && nx <= m && 1 <= ny && ny <= n){
                int news;
                if (a[nx][ny] == s[p + 1]) news = p + 1;
                else news = p;
                if (dp[nx][ny][news] < 0){
                    dp[nx][ny][news] = dp[x][y][p] + 1;
                    q.push(state(nx, ny, news));
                }
            }
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
 