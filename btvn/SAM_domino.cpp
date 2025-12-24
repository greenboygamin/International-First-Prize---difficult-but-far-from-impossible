#include <bits/stdc++.h>
using namespace std;

#define task "SORT"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = LLONG_MAX;
const ll MOD = 998244353;

int r, c;
char a[M][M], wood[M][M];
int startx, starty;
int tota = 0, ans = 0, total = 0, dist[M][M];
bool check[N], visited[M][M];
char sto[] = {'a', 'e', 'i', 'o', 'u', 'y'};

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void dfs(int x, int y){
    cout << x << " " << y << el;
    visited[x][y] = 1;
    bool ok = 0;
    for (int i = 0; i < 6; i++){
        if (a[x][y] == sto[i]){
            if (!check[sto[i] - 'a']){
                check[sto[i] - 'a'] = 1;
                tota++;
            }
        }
    }
    if (x > 2){
        if (wood[x - 2][y] == '|' && !visited[x - 2][y]) dist[x - 2][y] = dist[x][y] + 1, dfs(x - 2, y);
    }
    if (y > 2){
        if (wood[x][y - 2] == '-' && !visited[x][y - 2]) dist[x][y - 2] = dist[x][y] + 1, dfs(x, y - 2);
    }
    if (x < r - 1){
        if (wood[x + 2][y] == '|' && !visited[x + 2][y]) dist[x + 2][y] = dist[x][y] + 1, dfs(x + 2, y);
    }
    if (y < c - 1){
        if (wood[x][y + 2] == '-' && !visited[x][y + 2]) dist[x][y + 2] = dist[x][y] + 1, dfs(x, y + 2);
    }
}

void Solve() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> a[i][j]; check[a[i][j] - 'a'] = 1;
        }
    }
    for (int i = 0; i < 6; i++) total += (check[sto[i] - 'a'] == 1);
    memset(check, 0, sizeof check);
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> wood[i][j];
            if (wood[i][j] == '.'){
                startx = i; starty = j;
            }
        }
    }


    cout << total << el;
    cout << startx << " " << starty << el;
    dfs(startx, starty);
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cout << dist[i][j] << " ";
        }
        cout << el;
    }
}

int main() {
    Task();
    Solve();
    return 0;
}
