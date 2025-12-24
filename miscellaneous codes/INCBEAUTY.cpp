#include <bits/stdc++.h>
using namespace std;
#define task "INCBEAUTY"
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
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;
const ll MAX_K = 2e18; 

ll L, H, T;
ll dp[N][12];
ll S[N][12];
ll C[12];
string s;
ll dpm[20][12][2][2]; 
int max_b = 10; 

int get(ll x) {
    if (x == 0) return 0;
    string sx = to_string(x);
    int b = 0;
    for (char c : sx) {
        if (c == '6' || c == '8') b++;
    }
    return b;
}

ll dp_cnt(int pos, int b_rem, bool tight, bool lz) {
    if (b_rem < 0) return 0;
    if (pos == s.length()) return (b_rem == 0);
    if (!tight && !lz && dpm[pos][b_rem][tight][lz] != -1) return dpm[pos][b_rem][tight][lz];

    ll res = 0;
    int lim = tight ? (s[pos] - '0') : 9;

    for (int d = 0; d <= lim; d++) {
        int is_68 = (d == 6 || d == 8);
        int nb_rem = b_rem;
        if (is_68 && (!lz || d > 0)) {
            nb_rem--;
        }
        res += dp_cnt(pos + 1, nb_rem, tight && (d == lim), lz && (d == 0));
    }

    if (!tight && !lz) dpm[pos][b_rem][tight][lz] = res;
    return res;
}

ll calc_cnt(ll n, int b) {
    if (n < 0) return 0;
    if (n == 0) return (b == 0);
    s = to_string(n);
    memset(dpm, -1, sizeof(dpm));
    return dp_cnt(0, b, true, true);
}

ll safe_mul(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > MAX_K / b) return MAX_K;
    return min(MAX_K, a * b);
}

ll safe_add(ll a, ll b) {
    if (a > MAX_K - b) return MAX_K;
    return a + b;
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
    cin >> L >> H >> T;
    for(int b = 0; b <= max_b; b++) {
        C[b] = calc_cnt(H, b) - calc_cnt(L - 1, b);
    }
    for(int b = 0; b <= max_b + 1; b++) S[0][b] = 1;
    for (int i = 1; i < N; i++) { 
        for (int b = max_b; b >= 0; b--) { 
            dp[i][b] = safe_mul(C[b], S[i-1][b]);
            S[i][b] = safe_add(S[i][b+1], dp[i][b]);
        }
    }

    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        if (S[n][0] < k) {
            cout << -1 << el;
            continue;
        }
        vll ans;
        int last_b = 0;
        ll cur_L = L;
        for (int i = 0; i < n; i++) {
            ll val = H + 1;
            ll l = cur_L, r = H;
            while (l <= r) {
                ll mid = l + (r - l) / 2;
                if (mid < l) break;
                ll dem = 0;
                for (int b = last_b; b <= max_b; b++) {
                    ll num_b = calc_cnt(mid, b) - calc_cnt(cur_L - 1, b);
                    ll suff = S[n - 1 - i][b];
                    dem = safe_add(dem, safe_mul(num_b, suff));
                }
                
                if (dem >= k) {
                    val = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
            ans.pb(val);
            ll duoi = 0;
            for (int b = last_b; b <= max_b; b++) {
                ll num_b = calc_cnt(val - 1, b) - calc_cnt(cur_L - 1, b);
                ll suff = S[n - 1 - i][b];
                duoi = safe_add(duoi, safe_mul(num_b, suff));
            }
            
            k -= duoi;
            last_b = get(val);
            cur_L = L; 
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}