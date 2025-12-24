//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "dart"
#define maxn 102
#define oo 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;
// 1-n : Dinh loai G
// n+1 -2n: Dinh loai M

int n, a[maxn][maxn], id[maxn][maxn];
int d[maxn], tr[maxn], luu[maxn];
bool kt[maxn];


void Nhap()
{
    memset(a, 60, sizeof(a));
    cin >> n;
    int u, v, w1, w2, dem = 0;
    char type;
    while (cin >> u >> v >> w1 >> w2 >> type)
    {
        if (type == 'G') v += n;
            else u += n;
        dem ++;
        if (w1 < a[u][v])
        {
            a[u][v] = w1;
            id[u][v] = dem;
        }
        if (a[v][u] > w2)
        {
            a[v][u] = w2;
            id[v][u] = dem;
        }
    }
}

void IJK()
{
    memset(d, 60, sizeof(d));
    memset(kt, 0, sizeof(kt));
    d[n] = d[n+n] = 0;
    while (1)
    {
        int u = 0;
        for (int i = 1; i <= n+n; i++)
            if (d[i] < d[u] && !kt[i]) u = i;
        if (u == 1 || u == n+1) break;
        kt[u] = 1;
        for (int v = 1; v <= n+n; v++)
            if (d[v] > d[u] + a[u][v])
            {
                d[v] = d[u] + a[u][v];
                tr[v] = u;
            }
    }
}

void Ghikq()
{
    int res = d[1];
    int u = 1;
    if (d[1] > d[n+1]) res = d[n+1], u = n+1;
    int dem = 0;
    while (u != n && u != n+n)
    {
        luu[++dem] = u;
        u = tr[u];
    }
    luu[++dem] = u;

    cout << res << endl; 
    //for (int i = dem; i >= 1; i--)
      //  cout << ((luu[i] <= n)? luu[i] : luu[i]-n) << " ";
    //cout << endl;
    //for (int i = dem; i >= 2; i--)
      //  cout << id[luu[i]][luu[i-1]] << " ";

}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    Nhap();
    IJK();
    Ghikq();
    return 0;
}

