#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

int n, q; string s;
int a1[N], a2[N]; 
//a1[i] stores 1 if s[i] == s[i + 1]
//a2[i] stores 1 if s[i] == s[i + 2]

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

struct FenwickTree{
    int tree[N];

    void update(int idx, int val){
        if (idx < 1) return;
        for (; idx <= n; idx += idx & -idx) tree[idx] += val;
    }

    int get(int idx){
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }

    int query(int l, int r){
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
    
} bit1, bit2;

void upd_pos1(int i){
    if (i < 1 || i > n) return;
    int cur = (s[i] == s[i + 1]);
    if (cur != a1[i]){
        bit1.update(i, cur - a1[i]);
        a1[i] = cur;
    }
}

void upd_pos2(int i){
    if (i < 1 || i > n) return;
    int cur = (s[i] == s[i + 2]);
    if (cur != a2[i]){
        bit2.update(i, cur - a2[i]);
        a2[i] = cur;
    }
}

void solve() {
    cin >> n >> q >> s;
    s = " " + s;
    for (int i = 1; i < n; i++){
        if (s[i] == s[i + 1]){
            a1[i] = 1;
            bit1.update(i, 1);
        }
    }
    for (int i = 1; i < n - 1; i++){
        if (s[i] == s[i + 2]){
            a2[i] = 1;
            bit2.update(i, 1);
        }
    }
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int i, j; cin >> i >> j;
            swap(s[i], s[j]);   
            set<int> p1 = {i - 1, i, j - 1, j};
            set<int> p2 = {i - 2, i, j - 2, j};
            for (int p : p1) upd_pos1(p);
            for (int p : p2) upd_pos2(p);
        }
        else {
            int l, r; cin >> l >> r;
            if (bit1.query(l, r - 1) > 0 || bit2.query(l, r - 2) > 0){
                cout << 0 << el;
            }
            else cout << 1 << el;
        }
    } 
}

int main() {
    tassk(); 
    solve();
    return 0;
}

/*
 █████       █████  █████   █████████  █████   ████ █████ █████
▒▒███       ▒▒███  ▒▒███   ███▒▒▒▒▒███▒▒███   ███▒ ▒▒███ ▒▒███ 
 ▒███        ▒███   ▒███  ███     ▒▒▒  ▒███  ███    ▒███  ▒███ 
 ▒███        ▒███   ▒███ ▒███          ▒███████     ▒███  ▒███ 
 ▒███        ▒███   ▒███ ▒███          ▒███▒▒███    ▒███  ▒███ 
 ▒███      █ ▒███   ▒███ ▒▒███     ███ ▒███ ▒▒███   ▒███  ▒███ 
 ███████████ ▒▒████████   ▒▒█████████  █████ ▒▒████ █████ █████
▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒ 
*/