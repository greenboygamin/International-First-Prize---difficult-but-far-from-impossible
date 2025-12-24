#include <bits/stdc++.h>
using namespace std;

#define task "MOVE"
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

const ll N_MAX_GLOBAL = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 4e18;

struct Diem {
    ll x, y;
};

ll d(const Diem& p1, const Diem& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int n, k;
ll dp[M][M];
Diem a[M];

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
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++){
            dp[i][j] = INF;
        }
    }
    
    dp[1][0] = 0;
    
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= k; j++){
            
            int p_start = max(1, i - 1 - k);
            
            for (int p = p_start; p < i; p++){
                int skipped = i - 1 - p;
                
                if (j >= skipped){ 
                    int j_prev = j - skipped;
                    
                    if (dp[p][j_prev] != INF) {
                        dp[i][j] = min(dp[i][j], dp[p][j_prev] + d(a[p], a[i]));
                    }
                }
            }
        }
    }
    
    ll res = INF;
    for (int j = 0; j <= k; ++j) {
        res = min(res, dp[n][j]);
    }

    cout << res << el;
}

int main() {
    tassk();
    solve();
    return 0;
}