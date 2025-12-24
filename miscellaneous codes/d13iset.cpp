#include <bits/stdc++.h>
using namespace std;

#define task "d13jobshop"
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
const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = INT_MAX;
const ll MOD = 998244353;

int n;
map<vector<int>, int> mp;
vector<int> zero(n, 0);

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void Solve() {
    cin >> n;
    int m = 1 << n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    mp[zero] = 0;
    for (int i = 0; i < m; i++) {
        vector<pair<vector<int>, int>> cur(mp.begin(), mp.end());
        for (auto &it : cur) {
            vector<int> sum = it.first;
            for (int j = 0; j < n; j++) sum[j] += a[i][j];
            int mask = it.second | (1 << i);
            if (mp.find(sum) == mp.end()) mp[sum] = mask;
            if (sum == zero && mask != 0) {
                string ans(m, '0');
                for (int k = 0; k < m; k++) if (mask >> k & 1) ans[k] = '1';
                cout << ans << el;
                return;
            }
        }
    }
}

int main() {
    Task();
    Solve();
    return 0;
}
