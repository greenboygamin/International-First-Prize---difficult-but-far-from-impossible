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
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "sconnect"
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m, top = 0, st[maxn], id[maxn], low[maxn], In[maxn], scc = 0, cnt = 0;
vi ke[maxn], res[maxn];

void Tarjan(int &u){
    low[u] = id[u] = ++ cnt;
    st[++top] = u;
    for (int &v : ke[u]){
        if (In[v]) continue;
        if (id[v]) low[u] = min (low[u], id[v]);
            else {
                Tarjan(v);
                low[u] = min(low[u], low[v]);
            }
    }

    if (low[u] == id[u]){
        scc++;
        while (1) {
            int v = st[top--];
            res[scc].PB(v);
            In[v] = scc;
            if (v == u) break;
        }
        sort(all(res[scc]));
    }
}

bool cmp(vi &p, vi &q){
    if (p.size() != q.size()) return p.size() < q.size();
    return p[0] < q[0];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        ke[u]. PB(v);
    }
    for (int i = 1; i <= n; i++)
        if (id[i] == 0) Tarjan(i);
    cout << scc << endl;
    sort(res+1, res+scc+1, cmp);
    for (int i = 1; i <= scc; i++){
        cout << res[i].size() << endl;
        for (int u : res[i]) cout << u << " ";
        cout << endl;
    }
    return 0;
}

