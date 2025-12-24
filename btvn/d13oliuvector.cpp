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
    cin >> n; int m = (1 << n);
    vector<vi> a(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<int> mask(m, 0);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != 0) mask[i] |= (1 << j);
        }
    }
    vector<int> pos(m, -1);
    vector<int> id(m);
    int cur = 0;
    int L = -1, R = -1;
    for (int i = 0; i < m; i++){
        int p = 0, pw = 1;
        for (int j = 0; j < n; j++){
            if (!(cur & (1 << j))) p += pw;
            pw *= 2;
        }
        if (pos[p] != -1){
            L = pos[p], R = i - 1;
            break;
        }
        else {
            id[i] = p;
            pos[p] = i;
            cur ^= mask[p];
        }
    }   
    vi ans;
    for (int i = L; i <= R; i++) ans.pb(id[i]);
    string res = ""; for (int i = 0; i < m; i++) res.pb('0');
    for (int i : ans) res[i] = '1';
    cout << res;
}

int main() {
    Task();
    Solve();
    return 0;
}
