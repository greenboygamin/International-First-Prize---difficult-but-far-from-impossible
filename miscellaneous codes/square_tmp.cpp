#include <bits/stdc++.h>
using namespace std;

#define task "SQUARE"
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

const ll B = 505;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1000009999;

ll N, M, T;
vector<tuple<ll, ll, int>> C;

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
    cin >> N >> M >> T;
    C.resize(T);
    for (int i = 0; i < T; ++i) {
        ll u, v;
        int x;
        cin >> u >> v >> x;
        C[i] = {u, v, x};
    }

    ll ans = 0;
    
    // V: A[1][1]
    // R: Row diff
    // C_: Col diff
    for (int V = 0; V < 2; ++V) {
        for (int R = 0; R < 2; ++R) {
            for (int C_ = 0; C_ < 2; ++C_) {
                bool ok = true;
                for (const auto& c : C) {
                    ll u, v;
                    int x;
                    tie(u, v, x) = c;
                    
                    ll u_par = (u - 1) % 2;
                    ll v_par = (v - 1) % 2;
                    
                    // A[u][v] = V XOR (u-1)R XOR (v-1)C
                    int expected = V ^ (R * u_par) ^ (C_ * v_par);
                    
                    if (expected != x) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = (ans + 1);
                }
            }
        }
    }
    
    cout << ans % MOD << el;
}

int main() {
    tassk();
    solve();
    return 0;
}