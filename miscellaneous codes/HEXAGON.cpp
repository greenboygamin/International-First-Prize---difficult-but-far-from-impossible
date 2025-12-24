    #include <bits/stdc++.h>
    using namespace std;

    #define task "HEXAGON"
    #define el "\n"
    #define pb push_back
    #define MASK(i) (1 << (i))
    #define BIT(x, i) (((x) >> (i)) & 1)

    typedef long long int ll;
    typedef long double ld;
    typedef vector<pair<ll, ll>> vpll;
    typedef vector<long long> vll;
    typedef vector<int> vi;
    typedef pair<int, int> pii;
    typedef vector<pii> vpii;
    typedef pair<ll, ll> pll;
    typedef stack<ll> sll;
    typedef queue<ll> qll;
    typedef deque<ll> dqll;
    typedef priority_queue<ll> pqll;
    const ll N = 1e6 + 17;
    const ll M = 1e3 + 7;
    const ll B = 131;
    const ll O = 100;
    const ll INF = LLONG_MAX;
    const ll MOD = 998244353;

    ll n, a[205][205][205], x, y, z;
    ll dp[205][205][205];
    int px[] = {1, -1, 0};
    int py[] = {0, 1, 1};
    int pz[] = {-1, 0, -1};

    void Task() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(task ".INP", "r")) {
            freopen(task ".INP", "r", stdin);
            freopen(task ".OUT", "w", stdout);
        }
    }

    bool check(int s){
        return (O - n <= s && s <= O + n);
    }

    void Solve() {
        cin >> n;
        int total = 1 + 3 * n * (n + 1);
        for (int i = O - n; i <= O + n; i++){
            for (int j = O - n; j <= O + n; j++){
                for (int k = O - n; k <= O + n; k++){
                    dp[i][j][k] = -INF;
                }
            }
        }
        for (int i = 1; i <= total; i++){
            int p, r, s; cin >> p >> r >> s;
            p += O; r += O; s += O;
            cin >> a[p][r][s];
        }
        cin >> x >> y >> z;
        x += O; y += O; z += O;
        dp[O][O - n][O + n] = a[O][O - n][O + n];
        for (int ki = -n; ki <= n; ki++){
            for (int p = O - n; p <= O + n; p++){
                for (int r = O - n; r <= O + n; r++){
                    int s = 3 * O - p - r;
                    if (!check(s)) continue;
                    if (a[p][r][s] == 0) continue;
                    int pp, pr, ps;
                    for (int dir = 0; dir < 3; dir++){
                        pp = p - px[dir];
                        pr = r - py[dir];
                        ps = s - pz[dir];
                        if (!check(pp) || !check(pr) || !check(ps)) continue;
                        if (dp[pp][pr][ps] == -INF) continue;
                        dp[p][r][s] = max(dp[p][r][s], dp[pp][pr][ps] + a[p][r][s]); 
                    }
                }
            }
        }
        cout << dp[x][y][z];
    }

    int main() {
        Task();
        Solve();
        return 0;
    }
