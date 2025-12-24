//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 1005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "tour"

using namespace std;

typedef long long ll;
typedef long double ld;

int n, s, t, res;
vector < pii > G[2][maxn];
vector < pii > e[maxn];
int d[maxn];
int f[maxn*2][maxn];

void IJK(){
    fill(d, d+n+1, MOD);
    d[t] = 0;
    priority_queue < pii > PQ;
    PQ.push({0,t});
    while (!PQ.empty()){
        int u = PQ.top().S;
        int cost = -PQ.top().F;
        PQ.pop();
        if (cost > d[u]) continue;
        for (auto x : e[u]){
            int v = x.F;
            int w = x.S;
            if (d[v] > cost + w){
                d[v] = cost + w;
                PQ.push({-d[v],v});
            }
        }
    }

}

void Read(vector < pii > g[])
{
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
        e[i].clear();
    For(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        e[u].PB({v,w});
        e[v].PB({u,w});
    }
    IJK();
    For(u, 1, n)
        for (auto x : e[u])
        {
            int v = x.F;
            int w = x.S;
            if (d[v] < d[u])
                g[u].PB({v,w});
        }
}

void Calc(int a[], int b[], int type){
    For(u, 1, n)
        if (a[u] != -1)
        {
            for (auto x: G[type][u])
            {
                int v = x.F;
                int w = x.S;
                b[v] = max(b[v], a[u]+w);
            }
        }
}

void DP(){
    memset(f, -1, sizeof f);
    f[0][s] = 0;
    for (int k = 0; k < n*2; k++)
        Calc(f[k], f[k+1], k%2);
    res = -1;
    for (int u = 1; u <= n; u++)
        if (f[n*2][u] != -1) return;
    for (int k = 1; k <= n*2; k++)
            res = max(res, f[k][t]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> s >> t;
    Read(G[0]);
    Read(G[1]);
    DP();
    cout << res;
    return 0;
}

