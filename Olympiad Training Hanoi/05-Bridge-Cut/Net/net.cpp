//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "net"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;
int n, m, par[maxn];
vector <int> a[maxn];
int num[maxn], low[maxn], cnt = 0, k, l;
int A[maxn], B[maxn], res;
bool isA[maxn], isB[maxn];

void DFS(int u){
    low[u] = num[u] = ++cnt;
    A[u] = isA[u];
    B[u] = isB[u];
    for (int &v : a[u]){
        if (v == par[u]) continue;
        if (par[v]) {MIN(low[u], num[v]);}
        else{
            par[v] = u;
            DFS(v);
            MIN(low[u], low[v]);
            A[u] += A[v];
            B[u] += B[v];
			if (low[v] >= num[v])
				res += (A[v] == k || A[v] == 0 || B[v] == l || B[v] == 0);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	if(fopen(Task".inp", "r")) {
		freopen(Task".inp", "r", stdin);
		freopen(Task".out", "w", stdout);
	}
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= k; i++) {
        int u; cin >> u; isA[u] = 1;
    }
    for (int i = 1; i <= l; i++) {
        int u; cin >> u; isB[u] = 1;
    }
    while (m--){
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    for (int i = 1; i <= n; i++)
        if (!par[i]){
            par[i] = -1;
            DFS(i);
        }
    cout << res << endl;
    return 0;
}

