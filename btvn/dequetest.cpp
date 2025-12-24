#include <bits/stdc++.h>
using namespace std;

#define task "SUMLR"
#define ll long long int
#define el "\n"
#define vll vector<long long>
const ll N = 1e6 + 2;

ll n, a[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    deque<ll> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push_front(a[i]);
    }
    q.pop_back();
    while (!q.empty()) {
        cout << q.back() << " ";
        q.pop_back();
    }
    cout << el;  // Ensure there's a newline at the end
}

int main() {
    tassk();
    solve();
    return 0;
}
