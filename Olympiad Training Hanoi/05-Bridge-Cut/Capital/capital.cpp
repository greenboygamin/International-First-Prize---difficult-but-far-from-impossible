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
#define Task "capital"
#define maxn 300005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;
int n, m, par[maxn], Cmax, C;
vector <int> a[maxn];
int num[maxn], low[maxn], cnt = 0;
bool iscut[maxn];

void DFS(int u){
    low[u] = num[u] = ++cnt;
    int nchild = (par[u] != -1);// số thành phần tách ra nếu xóa u đi
    for (int &v : a[u]){
        if (v == par[u]) continue;
        if (par[v]) {MIN(low[u], num[v]);}
        else{
            par[v] = u;
            DFS(v);
            MIN(low[u], low[v]);
            nchild += (low[v] >= num[u]);
        }
    }
    if (Cmax < nchild || (Cmax == nchild && u < C)) Cmax = nchild, C = u;
}

int main()
{
	ios_base::sync_with_stdio(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    int tplt = 0;
    Cmax = 1; C = 1;
    for (int i = 1; i <= n; i++)
        if (!par[i]){
            par[i] = -1;
            DFS(i);
            tplt++;
        }
    //cout << tplt << endl;
    cout << Cmax + tplt - 1 << " " << C;
    return 0;
}

