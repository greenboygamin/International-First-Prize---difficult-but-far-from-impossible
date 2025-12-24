#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<long long> vll;

const ll N = 1e5 + 5;
ll n, a[N];

void solve() {
    // Input reading
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < 2) {
        cout << n << endl; // If there's 0 or 1 element, LAP length is `n`
        return;
    }

    // Sort array for LAP checks
    sort(a, a + n);

    // Hashmap to track AP lengths
    unordered_map<int, int> dp[N];
    int max_len = 2; // Minimum LAP length

    // Calculate longest AP
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int diff = a[j] - a[i];
            dp[j][diff] = dp[i].count(diff) ? dp[i][diff] + 1 : 2;
            max_len = max(max_len, dp[j][diff]);
        }
    }

    // Output the result
    cout << max_len << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Commenting out file handling for debugging
    // freopen("AM.inp", "r", stdin);
    // freopen("AM.out", "w", stdout);

    solve();
    return 0;
}
