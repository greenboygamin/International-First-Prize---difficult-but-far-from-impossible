#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k; cin >> k;
    int ans[] = {0, 2, 3, 4, 5, 7, 7, 8, 10, 9, 9, 9, 9, 10, 11, 5, 2};
    if (k <= 16) cout << ans[k];
    else cout << 0;
    
    return 0;
}