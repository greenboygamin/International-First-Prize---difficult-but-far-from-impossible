//Dinh viet anh
#include <iostream>
#include<bits/stdc++.h>
#define maxm 300001
#define maxn 102001
using namespace std;
int n, m, num[maxn], low[maxn], kq[maxn], t = 0, dv = 0, dr = 0, st = 0, lt = 0, goc[maxn], scr[maxn], scv[maxn], tplt[maxn] ;
bool dd[maxn];
vector <int> ke[maxn];
struct mang
{
    int x, y;
} a[maxm];

void dfs(int u)
{
    st++;
    t++;
    num[u] = t;
    low[u] = num[u];
    kq[st] = u;
    for(int i = 0; i < ke[u].size(); i++)
    {
        int v = ke[u][i];
        if(!dd[v])
        {
            if(num[v]) low[u] = min(low[u], num[v]);
            else
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    int v;
    if(num[u] == low[u])
    {
        lt++;
        goc[lt] = u;
        do
        {
            v = kq[st--];
            tplt[v] = lt;
            dd[v] = 1;
        }
        while(v != u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("onearc.inp", "r", stdin);
    //freopen("onearc.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> a[i].x >> a[i].y;
        ke[a[i].x].push_back(a[i].y);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            dfs(i);
    for(int i = 1; i <= m; i++)
    {
        if(tplt[a[i].x] != tplt[a[i].y])
        {
            scr[tplt[a[i].x]]++;
            scv[tplt[a[i].y]]++;
        }
    }
    for(int i = 1; i <= lt; i++)
    {
        if(!scv[i]) dv++;
        if(!scr[i]) dr++;
    }
    if(dv == 1 && dr == 1)
    {
        cout << "YES" << endl;
        for(int i = 1; i <= lt; i++)
        if(!scr[i])
        {
            cout << goc[i]<< " ";
           // cerr << goc[i]<< " ";

            break;
        }
        for(int i = 1; i <= lt; i++)
        if(!scv[i])
        {
            cout << goc[i];
            //cerr << goc[i] << endl;
            break;
        }
    }
    else  {cout << "NO";}

    return 0;
}
