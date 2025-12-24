/***************************************************************************/
/**********************  NGUYEN VAN HIEU  **********************************/
/***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <stack>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define maxn 500003
#define maxc 1000000003
#define PB push_back

using namespace std;
struct data{
    int index,lowlink;
    data()
    {
        index = 0;
    };
    data(int _i, int _l)
    {
        index = _i;
        lowlink = _l;
    }
};


vector<int> a[maxn], l[maxn],G[maxn];
int tien[maxn];
data b[maxn];
stack <int> s;
int n,m,xp;
long long kq = 0;
int dem = 0;
bool dd[maxn], onstack[maxn], hg[maxn] ;
int d[maxn], pos[maxn], ke[maxn];
long long dp[maxn];
int nc = 0;


void nhap()
{
    cin >> n >> m;
    FOR(i,1,n) a[i].clear();
    int u,v;
    FOR(i,1,m)
    {
        scanf("%d%d", &u, &v);
        a[u].PB(v);
    }
    FOR(i,1,n) scanf("%d",&tien[i]);
    int p,q;
    cin >> xp >> p;
    memset(dd,0,sizeof(dd));
    FOR(i,1,p)
    {
        scanf("%d",&q);
        dd[q] = 1;
    }
}

void MIN( int &x, int y)
{
    if (x > y) x = y;
}

void Update_SCC( int u)
{
    d[++nc] = 0;
    int v;
    do
    {
        v = s.top();
        s.pop();
        l[nc].PB(v);
        onstack[v] = 1;
        d[nc] += tien[v];
        pos[v] = nc;
    } while (v != u);
}

void DFS( int u)
{
    dem ++;
    b[u] = data(dem,dem);
    s.push(u);
    for ( int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (onstack[v]) continue;
        if (b[v].index) MIN(b[u].lowlink, b[v].index);
        else
        {
            DFS(v);
            MIN(b[u].lowlink, b[v].lowlink);
        }
    }
    if (b[u].lowlink == b[u].index) Update_SCC(u);
}

void Tarjan()
{
    memset(onstack, 0 , sizeof(onstack));
    FOR(i,1,n)
        if (!b[i].index) DFS(i);
}

void Tinh_d()
{

}

void Make_Graph()
{
    memset(ke, 0, sizeof(ke));
    FOR(i,1,n) G[i].clear();
    FOR(i,1,n)
    {
        int u = pos[i];
        for( int j = 0; j < a[i].size(); j++)
        {
            int v = pos[a[i][j]];
            if (u != v)
            {
                G[u].PB(v);
                ke[v]++;
            }
        }
    }

}

void xet( int u)
{
    for(int i = 0; i < l[u].size(); i++)
    {
        int v = l[u][i];
        if (dd[v])
        {
            kq = max(kq,dp[u]);
            return;
        }
    }

}

void DP_Topo()
{
    FOR(i,1,nc)
        if (!ke[i]) s.push(i);
    memset(dp,130,sizeof(dp));
    while (!s.empty())
    {
        int u = s.top();
        if ( u == pos[xp]) dp[u] = d[u];
        xet(u);
        s.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            //if (v == u) continue;
            ke[v]--;
            if (ke[v] == 0) s.push(v);
            dp[v] = max(dp[v], dp[u] + d[v]);
        }
    }
}

void xuli()
{
    Tarjan();
    Make_Graph();
    DP_Topo();
}

void inra()
{
   
    cout << kq;
}

int main()
{
	//freopen("atm.inp", "r", stdin);
	//freopen("atm.out", "w", stdout);
    nhap();
    xuli();
    inra();
    return 0;
}
