#include <bits/stdc++.h>
using namespace std;

#define task "XGAME"
#define pb push_back
#define el "\n"
typedef long long ll;

const int N = 5005;
vector<int> adj[N];
int pa[N];
bool active[N];
int g[N];
int n;

void calc_g(int u) {
    g[u] = 0;
    for (int v : adj[u]) { 
        if (!active[v]) continue;
        calc_g(v);
        g[u] ^= (1 + g[v]);
    }
}

int find_move(int u, int target_g) {
    int curGu = 0;
    for(int v : adj[u]) if(active[v]) curGu ^= (1 + g[v]);
    for (int v : adj[u]) {
        if (!active[v]) continue;
        int pile_v = 1 + g[v];
        int pileV = curGu ^ pile_v ^ target_g; 
        if (pileV < pile_v) { 
            if (pileV == 0) {
                return v;
            }
            return find_move(v, pileV - 1);
        }
    }
    return -1;
}

void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> pa[i];
        adj[pa[i]].pb(i); 
    }
    fill(active, active + n + 1, true);
    calc_g(1);
    bool my_turn = (g[1] != 0);
    cout << (my_turn ? 1 : 0) << el;
    cout.flush();
    while (true) {
        if (my_turn) {
            int mNode = -1;
            if (g[1] != 0) {
                mNode = find_move(1, 0);
            } else {
                for(int v : adj[1]) {
                    if(active[v]) {
                        mNode = v;
                        break;
                    }
                }
            }
            if (mNode == -1) break;
            cout << mNode << el;
            cout.flush();
            active[mNode] = false;
        } else {
            int move;
            if (!(cin >> move)) break;
            if (move <= 0) break; 
            active[move] = false;
        }
        my_turn = !my_turn;
        bool ok = false;
        for(int i = 2; i <= n; i++) {
            if (active[i]) {
                ok = true;
                break;
            }
        }
        if (!ok) break;
        calc_g(1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
