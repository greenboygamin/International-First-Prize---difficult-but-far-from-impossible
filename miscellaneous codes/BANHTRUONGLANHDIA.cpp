#include <bits/stdc++.h>
using namespace std;

#define task "BTLN"
#define ll long long int
#define ld long double
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
const ll INF = 1e9 + 7;
ll a[M][M], n, m;
int px[] = {1, -1, 0, 0};
int py[] = {0, 0, 1, -1};
vector<vector<int>> chau(M, vector<int>(M, 0));
vector<vector<int>> sukuna(M, vector<int>(M, 0));

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void filler(int i, int j, vector<vector<int>> &kt){
    queue<pair<int, int>> q;
    q.push({i, j});
    kt[i][j] = 2;  
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int idx = 0; idx < 4; idx++){
            int cx = x + px[idx];
            int cy = y + py[idx];
            if (1 <= cx && cx <= n && 1 <= cy && cy <= m && kt[cx][cy] == 0){
                kt[cx][cy] = 2;
                q.push({cx, cy});
            }
        }
    }
}

void realfill(vector<vector<int>> &kt){
    for (int i = 1; i <= n; i++){
        if (kt[i][1] == 0) filler(i, 1, kt);
        if (kt[i][m] == 0) filler(i, m, kt);
    }
    for (int i = 1; i <= m; i++){
        if (kt[1][i] == 0) filler(1, i, kt);
        if (kt[n][i] == 0) filler(n, i, kt);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (kt[i][j] == 0){
                kt[i][j] = 1;
            }
            else if (kt[i][j] == 2){
                kt[i][j] = 0;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 1) chau[i][j] = 1;
            else if (a[i][j] == 2) sukuna[i][j] = 1;
            else if (a[i][j] == 3) {
                chau[i][j] = 1;
                sukuna[i][j] = 1;
            }
        }
    }
    ll dem = 0;
    realfill(sukuna);
    realfill(chau);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (chau[i][j] && sukuna[i][j]){
                dem++;
            }
        }
    }
    cout << dem << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
