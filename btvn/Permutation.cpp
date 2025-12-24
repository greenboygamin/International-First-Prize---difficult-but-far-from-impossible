#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
typedef long long int ll;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int cycle_length = 0;
            int x = i;

            // Traverse the cycle
            while (!visited[x]) {
                visited[x] = true;
                x = p[x] - 1; // Move to the next index in the cycle
                cycle_length++;
            }

            // If cycle_length > 2, we need (cycle_length - 1) swaps
            if (cycle_length > 2) {
                swaps += (cycle_length - 1);
            }
        }
    }

    cout << swaps << el;
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
