//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "kminpath"
#define maxn 10003
#define maxk 103
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

vector<pii> a[maxn];
int n, m,k;
int d[maxn][maxk];

void nhap()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].PB(mp(v,w));
        a[v].PB(mp(u,w));
    }
}

void IJK()
{
    memset(d, 119, sizeof(d)); //gan tat ca d[i] = 2004318071 > 2.10^9
    priority_queue < pair<int, int> > P;
    P.push(mp(0, 1));
    d[1][1] = 0;
    while (!P.empty())
    {
        // Tim dinh toi uu
        int u = P.top().S;
        int l = -P.top().F; // == d[u]
        P.pop();
        if (l > d[u][k]) continue;
        // Dung dinh u di toi uu
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].F;
            int newroad = l + a[u][i].S;
            int pos = lower_bound(d[v] + 1, d[v] + k + 2, newroad) - d[v];
			if (pos > k || d[v][pos] == newroad) continue;
            for (int j = k; j > pos; j--) d[v][j] = d[v][j-1];
            d[v][pos] = newroad;
			P.push(mp(-newroad,v ));
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    nhap();
    IJK();
    if (d[n][1] > 2000000000) cout << -1;
    else for (int i = 1; i <= k; i++) cout << d[n][i] << " ";
    return 0;
}
