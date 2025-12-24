#include <bits/stdc++.h>
using namespace std;

#define task "TRIANGLE"
#define el "\n"
#define pb push_back
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

int n;
bool check(int x1, int y1, int x2, int y2) {
    return x1 * x2 + y1 * y2 == 0;
}


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    int dem = 0;
    for (int x1 = 0; x1 <= n; x1++){
        for (int x2 = 0; x2 <= n; x2++){
            for (int y1 = 0; y1 <= n; y1++){
                for (int y2 = 0; y2 <= n; y2++){
                    int x3 = x2 - x1, y3 = y2 - y1;
                    if (x1 == x2 && y1 == y2) continue;
                    if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0)) continue;
                    if (check(x1, y1, x2, y2) || check(x2, y2, x3, y3) || check(x1, y1, x3, y3)) dem++;
                }
            }
        }
    }
    cout << dem / 2;
}

int main() {
    tassk();
    solve();
    return 0;
}
 