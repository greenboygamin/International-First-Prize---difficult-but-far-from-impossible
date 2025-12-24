#include <bits/stdc++.h>
using namespace std;

#define task "DIV11"
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

const int N_MAX = 100005;
const int MOD = 11;

int n;
string s;
ll p[N_MAX];
int cnt[MOD];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int proc(ll val) {
    return (val % MOD + MOD) % MOD;
}

void solve() {
    cin >> n >> s;
    
    vll a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = s[i-1] - '0';
    }
    
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll sign = (i % 2 != 0) ? 1 : -1;
        p[i] = p[i-1] + sign * a[i];
    }
    
    ll d_old = p[n];
    ll ans = 0;
    
    for (int j = 2; j <= n; ++j) {
        int i = j - 1;
        ll ki = (i % 2 != 0) ? 1 : -1;
        ll g_i = -2 * p[i] + ki * a[i];
        cnt[proc(g_i)]++;
        
        ll kj = (j % 2 != 0) ? 1 : -1;
        ll f_j = d_old - 2 * p[j-1] - kj * a[j];
        
        ans += cnt[proc(f_j)];
    }
    
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}