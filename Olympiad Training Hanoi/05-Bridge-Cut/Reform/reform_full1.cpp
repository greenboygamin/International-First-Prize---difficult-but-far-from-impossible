//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "reform"
#define maxn 200004
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m;
vector <int> a[maxn];

long long ans = 0;
int dd[maxn];
int sl[maxn], num, tplt;
int bridge = 0;
int index[maxn], low[maxn];
int id;
int ke[maxn];

void Read()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i].clear();
    memset(ke, 0, sizeof(ke));
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
        ke[u] ++;
        ke[v] ++;
    }
}

void DFS(int u)
{
    num++;
    dd[u] = 1;
    //cout << u << endl;
    //int p = sz(a[u]);
    int ii = ke[u] - 1;
    //for (int i = ke[u]-1; i >= 0; i--)
    while (ii >= 0)
    {
        int v = a[u][ii];
        if (dd[v] == 0) DFS(v);
        ii--;
    }
}

void Tinh_tplt()
{


    tplt = 0;
    for (int i = 1; i <= n; i++) dd[i] = 0;
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
        {
            tplt++;
            num = 0;
            if (tplt > 2) return;
            DFS(i);
            sl[tplt] = num;
        }
}

void DFS_Count(int u, int par)
{
    low[u] = index[u] = ++id;
    for (int i = 0; i < sz(a[u]); i++)
    {
        int v = a[u][i];
        if (v == par) continue;
        if (!index[v])
        {
            DFS_Count(v, u);
            bridge += low[v] == index[v];
        }
        low[u] = min(low[v], low[u]);
    }
}

void Sub2()
{
    memset(index, 0, sizeof(index));
    memset(low, 0, sizeof(low));
    id = 0;
    for (int i = 1; i <= n; i++)
        if (!index[i]) DFS_Count(i, -1);
    ans = 1ll*sl[1] * sl[2] * (m-bridge);
}

void DFS_final(int u, int par)
{
    low[u] = index[u] = ++id;
    sl[u] = 1;
    for (int i = 0; i < sz(a[u]); i++)
    {
        int v = a[u][i];
        if (v == par) continue;
        if (!index[v])
        {
            DFS_final(v, u);
            sl[u] += sl[v];
            if (low[v] == index[v]) ans += 1ll * sl[v] * (n-sl[v]) - 1, bridge++;
        }

        low[u] = min(low[v], low[u]);
    }
}


void Sub1()
{
    memset(index, 0, sizeof(index));
    memset(low, 0, sizeof(low));
    memset(sl, 0, sizeof(sl));
    id = 0;
    DFS_final(1, -1);
    ans += 1ll*(m-bridge) * ( 1ll * n *(n-1) / 2 - m);
//    if (bridge == 0) cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    Read();
//    for (int u = 1; u <= n; u++)
//        for (int i = 0; i < a[u].size(); i++) cout << u << " " << a[u][i] << endl;
    //return 0;
    Tinh_tplt();
    if (tplt > 2) ans = 0;
        else if (tplt == 2) Sub2();
        else Sub1();
    cout << ans;
//    cout << ans << endl << tplt << endl << n << endl;
//    cout << sl[1] << " " << sl[2];
    return 0;
}
