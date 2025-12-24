#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
typedef long long int ll;
const int MOD = 1e9 + 7;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

vector<int> depth;
vector<vector<int>> tree;
vector<int> distance_from_root;

void dfs(int v, int p, int d) {
    depth[v] = d;
    distance_from_root[v] = d; // Store distance from the root
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 2; i <= n / 2; i++){
        if (a[i] == a[i - 1] || a[n - i + 1] == a[n - i + 2]){
            swap(a[i], a[n - i + 1]);
        }
    }
    int dem = 0;
    for (int i = 2; i <= n; i++) dem += (a[i] == a[i - 1]);
    cout << dem << el;
}

int main() {
    tassk();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
