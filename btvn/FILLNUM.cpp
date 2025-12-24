#include <bits/stdc++.h>
using namespace std;

#define task "FILLNUM"
#define el "\n"
typedef long long ll;

const ll N = 1e7 + 5;

ll n, m, k;
int a[N];
int nex[N];

struct Query {
    ll i, j, c;
};

void tassk() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int findnext(int pos) {
    if (pos < 1 || pos > n) return -1;
    if (a[pos] == -1) 
        return pos;
    return nex[pos] = findnext(nex[pos]);
}

void dofill(int i, int j, int c) {
    for (int x = findnext(i); x != -1 && x <= j; x = findnext(x)) {
        a[x] = c;
        nex[x] = x + 1;  
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        a[i] = -1;
        nex[i] = i + 1;
    }
    nex[n+1] = -1;  
    stack<Query> st;
    for (int t = 0; t < m; t++) {
        ll i, j, c;
        cin >> i >> j >> c;
        st.push({i, j, c});
    }
    while (!st.empty()) {
        auto q = st.top(); st.pop();
        dofill(q.i, q.j, q.c);
    }
    dofill(1, n, 0);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res * 10 + a[i]) % k;
    }
    cout << res << el;
}

int main(){
    tassk();
    solve();
    return 0;
}
