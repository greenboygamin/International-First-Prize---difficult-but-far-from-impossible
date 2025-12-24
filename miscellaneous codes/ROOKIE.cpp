#include <bits/stdc++.h>
using namespace std;
#define task "ROOKIE"
#define el "\n"

int r, c, q;
int b[105][105];

void tassk() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> r >> c >> q;
    if(r > 100 || c > 100) {
        while(q--) {
            int u, v; cin >> u >> v;
            cout << 0 << el;
        }
        return;
    }

    while(q--) {
        int x, y; cin >> x >> y;
        b[x][y] ^= 1;
        int ans = 0;
        for(int i=1; i<=r; ++i) {
            for(int j=1; j<=c; ++j) {
                if(b[i][j]) continue;
                int cnt = 0;
                for(int k=i-1; k>=1; --k) if(b[k][j]) { cnt++; break; }
                for(int k=i+1; k<=r; ++k) if(b[k][j]) { cnt++; break; }
                for(int k=j-1; k>=1; --k) if(b[i][k]) { cnt++; break; }
                for(int k=j+1; k<=c; ++k) if(b[i][k]) { cnt++; break; }
                
                if(cnt == 1) ans++;
            }
        }
        cout << ans << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}