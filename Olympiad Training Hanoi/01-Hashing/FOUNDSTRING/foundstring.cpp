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
#define Task "foundstring"
#define maxn 1000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string A, B;
int n, m;

const int Base = 101;
const long long MM = 1ll * MOD * MOD;

long long H[maxn], Sum[maxn];

int Get_hash(int u, int v){
    return (Sum[v] - Sum[u-1] * H[v-u+1] + MM) % MOD;	    	
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> A >> B;
    n= A.length(); A = " " + A;
    m = B.length(); B = " " + B;

    Sum[0] = 0;
    for (int i = 1; i <= m; i++) Sum[i] = ((Sum[i-1] * Base) + B[i]) % MOD;
    H[0] = 1; // H[i] = Base^i
    for (int i = 1; i <= m; i++) H[i] = (H[i-1] * Base) % MOD;
    long long hashA = 0;
    for (int i = 1; i <= n; i++) hashA = ((hashA * Base) + A[i]) % MOD;
    vector <int> res;
    for (int v = n; v <= m; v++){
        int u = v - n + 1;
        if (hashA == Get_hash(u,v)) res.PB(u);
    }
    cout << res.size() << endl;
    for (int x: res) cout << x << " ";
    return 0;
}

