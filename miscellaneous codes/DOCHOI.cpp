#include <bits/stdc++.h>
using namespace std;

#define task "DOCHOI"
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

const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 4e18;

int w, k, h, l, xh, yh, xv, yv, tr, tc;
int h_prev[M][M], w_prev[M][M];
char a[M][M];
set<tuple<int, int, int, int>> check;

struct states{
    int c, r, i, j;
};

queue<states> q;

bool check_h(int r, int c1, int c2){
    
}

bool check_w(int c, int r1, int r2){

}

bool check(int c, int r, int i, int j){

}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> w >> h >> k >> l >> xh >> yh >> xv >> yv;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> a[i][j];
            if (a[i][j] == '*'){
                tr = i; tc = j;
            }
            int obs = (a[i][j] == 'x');
            h_prev[i][j] = (i > 0) ? h_prev[i - 1][j] + obs;
            w_prev[i][j] = (j > 0) ? w_prev[i][j - 1] + obs; 
        }
    }
    
}

int main() {
    tassk();
    solve();
    return 0;
}