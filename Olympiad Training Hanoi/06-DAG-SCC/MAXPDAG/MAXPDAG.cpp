//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "MAXPDAG"
#define maxn 100002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

vector < pii >  a[maxn];
int n, m;
int d[maxn];


void nhap()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u].PB(mp(v,w));
    }
}

void DFS(int u)
{
    d[u] = 0;
    for (pii &p : a[u]){
        int v = p.F;
        int w = p.S;
        if (d[v] == -1) DFS(v);
        d[u] = max(d[u], d[v] + w);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    nhap();
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++)
        if (d[i] == -1) DFS(i);
    cout << *max_element(d+1, d+n+1);
    return 0;
}
