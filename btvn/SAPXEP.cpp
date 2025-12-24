#include <bits/stdc++.h>
using namespace std;

#define task "SAPXEP"
#define el "\n"
typedef long long int ll;
typedef vector<int> vi;
typedef pair<ll, int> pli;

const int N = 3e5 + 5;

int n;
ll a[N], b[N];
int T[N]; 
ll bit[N];

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += val;
    }
}

ll query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

ll count_inversions() {
    ll inversions = 0;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
        inversions += query(n) - query(T[i]);
        update(T[i], 1);
    }
    return inversions;
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
    cin >> n;
    
    ll sumA = 0, sumB = 0;
    vector<pli> LA(n), LB(n); 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sumA += a[i];
        LA[i] = {a[i], i + 1}; 
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sumB += b[i];
        LB[i] = {b[i], i + 1}; 
    }

    if (sumA != sumB) {
        cout << -1 << el;
        return;
    }
    sort(LA.begin(), LA.end());
    sort(LB.begin(), LB.end());
    for (int i = 0; i < n; i++) {
        int idxA = LA[i].second;
        int idxB = LB[i].second;
        T[idxA] = idxB;
    }
    cout << count_inversions() << el;
}

int main() {
    tassk();
    solve();
    return 0;
}