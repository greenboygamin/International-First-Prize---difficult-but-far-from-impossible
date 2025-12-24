    #include <bits/stdc++.h>
    using namespace std;

    #define task "unblock"
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
    const ll INF = LLONG_MAX;
    const ll MOD = 998244353;

    ll n, m, startx, starty;
    ll old_tmp;
    ll a[M][M];
    char wood[M][M];
    bool visited[M][M];
    ll ans = 0, tmp = 0;

    void Task() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen(task ".INP", "r")) {
            freopen(task ".INP", "r", stdin);
            freopen(task ".OUT", "w", stdout);
        }
    }

    ll dfs(int x, int y){
        visited[x][y] = 1;
        ll cur = a[x][y];    
        if (x > 2){
            if (wood[x - 2][y] == 'V' && !visited[x - 2][y]) cur += max(0LL, dfs(x - 2, y));
        }
        if (y > 2){
            if (wood[x][y - 2] == 'H' && !visited[x][y - 2]) cur += max(0LL, dfs(x, y - 2));
        }
        if (x < n){
            if (wood[x + 1][y] == 'V' && !visited[x + 1][y]) cur += max(0LL, dfs(x + 2, y));
        }
        if (y < m){
            if (wood[x][y + 1] == 'H' && !visited[x][y + 1]) cur += max(0LL, dfs(x, y + 2));
        }
        return cur;
    }

    void Solve() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> wood[i][j];
                if (wood[i][j] == 'O'){
                    startx = i, starty = j;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        ans = dfs(startx, starty);
        cout << ans << el;
    }

    int main() {
        Task();
        Solve();
        return 0;
    }
