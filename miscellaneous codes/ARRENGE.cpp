#include <bits/stdc++.h>
using namespace std;

#define task "ARRENGE"
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
const ll M = 1e3 + 5;
const ll INF = 4e18;

int n, q;
int p[N];

int find(int i) {
    int root = i;
    while (root != p[root]) {
        root = p[root];
    }
    
    while (i != root) {
        int next = p[i];
        p[i] = root;
        i = next;
    }
    return root;
}

void unite(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) {
        p[i] = j;
    }
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
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int k = 0; k < q; k++) {
        int t, x, y;
        cin >> t >> x >> y;
        
        if (t == 1) {
            unite(x, y);
        } 
        else if (t == 2) {
            for (int j = x; j < y; j++) {
                unite(j, j + 1);
            }
        } 
        else {
            if (find(x) == find(y)) {
                cout << "YES" << el;
            } else {
                cout << "NO" << el;
            }
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}