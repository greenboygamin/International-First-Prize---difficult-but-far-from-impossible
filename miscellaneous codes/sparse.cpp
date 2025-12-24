#include <bits/stdc++.h>
using namespace std;

#define task "maxsegment"
#define el "\n"
typedef long long ll;
const int N = 5e5 + 5;

int n, k;
int a[N];
int sp[N][20], lg2[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void build_sparse() {
    for (int i = 1; i <= n; i++) sp[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
}

int get_max(int L, int R) {
    int j = lg2[R - L + 1];
    return max(sp[L][j], sp[R - (1 << j) + 1][j]);
}

void preprocess_log() {
    lg2[1] = 0;
    for (int i = 2; i < N; i++)
        lg2[i] = lg2[i / 2] + 1;
}

void solve() {
    int t;
    cin >> t >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    preprocess_log();
    build_sparse();

    for (int i = 1; i <= n - k + 1; i++)
        cout << get_max(i, i + k - 1) << ' ';
    cout << el;
}

int main() {
    tassk();
    solve();
    return 0;
}