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
#define Task "blo"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, cau = 0, tplt = 0, cnt = 0;
long long Scau;
vector <int> a[maxn];
int index[maxn], low[maxn], S[maxn], T[maxn], par[maxn];
long long res[maxn];

void DFS(int u){
    int x = (par[u] != -1);
    int sum = 0;
    T[u] = 1;
    low[u] = index[u] = ++cnt;
    for (int v : a[u])
        if (v != par[u])
            if (index[v]) low[u] = min(low[u], index[v]);
                else{
                    par[v] = u;
                    DFS(v);
                    low[u] = min(low[u], low[v]);
                    T[u] += T[v];
                    if (low[v] >= index[u]){
                        x ++;
                        res[u] += (long long) T[v] * (n-T[v]-1);
                        sum += T[v];
                    }
                }
    if (x >= 2) res[u] += (long long)sum * (n-sum-1);
        else res[u] = 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (int u, v, i = 0; i < m; i++){
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    reset(index);
    for (int i = 1; i <= n; i++)
        if (index[i] == 0){
            par[i] = -1;
            DFS(i);
    }
    for (int i = 1; i <= n; i++) cout << res[i] + n+n-2 << "\n";
    return 0;
}

