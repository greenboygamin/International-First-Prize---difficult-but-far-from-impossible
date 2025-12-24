#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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
const ll MOD = 2e18;

int n;
int a[2][N];
int c[2][N];
int px[] = {0, 1, 1, 0};
int py[] = {0, 0, 1, 1};
vi res;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void rot(int j){
    if (j < 1 || j >= n) return;
    int tmp = c[0][j];
    c[0][j] = c[0][j + 1];
    c[0][j + 1] = c[1][j + 1];
    c[1][j + 1] = c[1][j];
    c[1][j] = tmp;
    if (n != 2) res.pb(j);
}

void swapud(int up, int down){
    if (up == down + 1){
        rot(down);
        rot(down);
        rot(down);
    }
    else if (up + 1 == down){
        rot(up);
    }
    else if (up < down){
        for (int i = up; i <= down - 2; i++){
            rot(i);
            rot(i);
            rot(i);
        }
        rot(down - 1);
        rot(down - 1);
        for (int i = down - 2; i >= up; i--){
            rot(i);
        }
    }
    else if (up > down){
        for (int i = down; i <= up - 2; i++){
            rot(i);
        }
        rot(up - 1);
        rot(up - 1);
        for (int i = up - 2; i >= down; i--){
            rot(i);
            rot(i);
            rot(i);
        }
    }
    else if (up == down){
        if (up + 1 < n) {
            rot(up + 1);
            rot(up + 1);
            rot(up + 1);
            rot(up);
            rot(up);
            rot(up);
            rot(up + 1);
        }
        else if(up > 2 && up <= n){
            rot(up - 2);
            rot(up - 1);
            rot(up - 2);
            rot(up - 2);
            rot(up - 2);
        }
        else{
            rot(up - 1);
            rot(up);
            rot(up);
            rot(up);
            rot(up - 1);
            rot(up - 1);
            rot(up);
            rot(up - 1);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= n; i++) cin >> a[1][i];
        for (int i = 0; i < 2; i++) 
        for (int j = 1; j <= n; j++) c[i][j] = a[i][j];

    if (n == 2){
        vector<int> mx(4, 0);
        int best = 0;
        for (int i = 0; i < 4; i++){
            rot(1);
            mx[i] = c[0][1] + c[0][2];
            best = max(best, mx[i]);
        }
        for (int i = 1; i <= 4; i++){
            if (mx[i - 1] == best){
                for (int j = 1; j <= i; j++) res.pb(1);
                break;
            }
        }
        cout << res.size() << el;
        for(int x : res) cout << x << ' ';
        return;
    }

    vector<pair<int, int>> b;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
            b.pb({a[i][j], i * n + j});

    sort(b.rbegin(), b.rend());
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++) c[i][j] = 0;

    for (int i = 0; i < n; i++){
        int pos = b[i].second;
        int x = (pos - 1) / n;
        int y = (pos - 1) % n + 1;
        c[x][y] = 1;
    }

    int i = 1, j = 1;
    while (i <= n && j <= n){
        while (i <= n && c[0][i] != 0) i++;
        while (j <= n && c[1][j] != 1) j++; 

        if (i > n || j > n) break;

        swapud(i, j);
    }

    cout << res.size() << el;
    for(int x : res) cout << x << ' ';
}

int main() {
    tassk(); 
    solve();
    return 0;
}