#include <bits/stdc++.h>
using namespace std;

#define task "sweets"
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

int n, q, a[N], st[N], en[N];
vector<int> adj[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

struct FenwickTree{
    int size; vector<int> bit;

    void init(int n){
        bit.assign(4 * n, 0);
        size = n;
    }

    void update(int i, int val){
        while ()
    }

} BIT;

/*struct FenwickTree {
    int size;
    vector<int> bit;

    void init(int n) {
        size = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        while (i <= size) {
            bit[i] += val;
            i += i & (-i);
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & (-i);
        }
        return res;
    }

    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
} BIT;
*/

void Solve() {
    cin >> n >> q;    

}

int main() {
    Task();
    Solve();
    return 0;
}
