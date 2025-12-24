#include <bits/stdc++.h>
using namespace std;

#define task "greedy-is-wrong"
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

int n;
char a[M][M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool check(int row, char c){
    char b[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        if (i == row){
            for (int j = 1; j <= n; j++){
                b[i][j] = c;
            }
        }
        else for (int j = 1; j <= n; j++) b[i][j] = a[i][j];
    }
    for (int j = 1; j <= n; j++){
        int dem = 0;
        for (int i = 1; i <= n; i++){
            if (b[i][j] == b[i - 1][j]) dem++;
            else dem = 1;
            if (dem >= n / 2 + 1) return false;
        }
    }
    return true;
}


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    bool ok = 1;
    for (int j = 1; j <= n; j++){
        int dem = 0;
        for (int i = 1; i <= n; i++){
            if (a[i][j] == a[i - 1][j]) dem++;
            else dem = 1;
            if (dem >= n / 2 + 1){
                ok = 0;
                break;
            }
        }
    }
    if (ok){
        cout << 0 << el;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (check(i, 'W') || check(i, 'B')){
            cout << 1;
            return;
        }
    }
    cout << 2;
}


int main() {
    tassk();
    solve();
    return 0;
}   