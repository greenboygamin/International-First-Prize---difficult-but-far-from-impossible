#include <bits/stdc++.h>
using namespace std;

#define task "SORT"
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
const ll INF = LLONG_MAX;
const ll MOD = 998244353;

int n, c[N], q;
pii a[N], aa[N];
ll pref[N], suf[N], pos[N];
set<int> s;

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

struct Query{
    int type, x, y;
};
vector<Query> queries;

struct SegmentTree{
    int size; vector<int> st; vector<int> lazy;

    void init(int n){
        st.assign(n + 4, 0);
        lazy.assign(n + 4, 0);
        size = n;
    }

    void push(int id, int l, int r){
        
    }
};

void compress(){
    vector<int> b(s.begin(), s.end());
    for (int i = 1; i <= n; i++) a[i].second = lower_bound(b.begin(), b.end(), a[i].first) - b.begin() + 1;
    
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        s.insert(a[i].first);
    }
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }
    compress();
    for (int i = 1; i <= n; i++){
        aa[i] = a[i];
    }
    sort(aa + 1, aa + n + 1);
    for (int i = 1; i <= n; i++){
        pos[aa[i].second] = i;
    }

}

int main() {
    Task();
    Solve();
    return 0;
}
