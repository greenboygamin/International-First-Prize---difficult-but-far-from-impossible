#include <bits/stdc++.h>
using namespace std;
#define task "test"
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
const ll N = 2e5 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const int MOD[2] = {1000000009, 1000000037};

int n, m;
string a, b;
int pw[2][N], iv[2][N];
int h[2][N];
int pf[N][26];
int cnt[26];
int P;

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

ll mpow(ll a, ll b, int k) {
    ll res = 1;
    for (; b; b >>= 1, a = a * a % MOD[k])
        if (b & 1) res = res * a % MOD[k];
    return res;
}

void pre(int len) {
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    P = uniform_int_distribution<int>(31, 500)(rd);
    for (int k = 0; k < 2; k++) {
        pw[k][0] = 1;
        for (int i = 1; i <= len; i++) pw[k][i] = 1ll * pw[k][i - 1] * P % MOD[k];
        iv[k][len] = mpow(pw[k][len], MOD[k] - 2, k);
        for (int i = len - 1; i >= 0; i--) iv[k][i] = 1ll * iv[k][i + 1] * P % MOD[k];
    }
}

void solve() {
    cin >> a >> b;
    n = a.size(); m = b.size();
    if (n > m) { cout << 0; return; }
    
    a = " " + a; b = " " + b;
    pre(m);

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 26; j++) pf[i][j] = pf[i - 1][j];
        pf[i][b[i] - 'a']++;
        for (int k = 0; k < 2; k++) 
            h[k][i] = (h[k][i - 1] + 1ll * (b[i] - 'a') * pw[k][i]) % MOD[k];
    }

    for (int i = 1; i <= n; i++) cnt[a[i] - 'a']++;

    int ans = 0;
    map<pii, bool> vis;

    for (int l = 1; l + n - 1 <= m; l++) {
        int r = l + n - 1;
        int v0 = 1ll * (h[0][r] - h[0][l - 1] + MOD[0]) % MOD[0] * iv[0][l - 1] % MOD[0];
        int v1 = 1ll * (h[1][r] - h[1][l - 1] + MOD[1]) % MOD[1] * iv[1][l - 1] % MOD[1];

        if (vis[{v0, v1}]) continue;
        vis[{v0, v1}] = 1;

        bool ok = 1;
        for (int j = 0; j < 26; j++) {
            if (pf[r][j] - pf[l - 1][j] != cnt[j]) {
                ok = 0; break;
            }
        }
        if (ok) ans++;
    }
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}