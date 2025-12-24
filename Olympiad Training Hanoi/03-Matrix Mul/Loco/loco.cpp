//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "loco"
#define maxn 4
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

int  M;
long long n;
int F[3] = {1,1,2};

struct matrix
{
    int val[maxn][maxn];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }

    matrix operator * ( const matrix & x)
    {
        matrix res;
        for (int u = 1; u <= 3; u++)
            for (int v = 1; v <= 3; v++)
                for (int i = 1; i <= 3; i++)
                    res.val[u][v] = ((ll)val[u][i] * x.val[i][v] + res.val[u][v] ) % M;
        return res;
    }
};

matrix A;

matrix POWW(matrix A, long long b)
{
    matrix C;
    C.val[1][1] = C.val[2][2] = C.val[3][3] = 1;
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n >> M;
    if (n < 3)
    {
        cout << F[n] % M;
        return 0;
    }
    A.val[1][1] = A.val[1][2] = A.val[1][3] = A.val[2][1] = A.val[3][2] = 1;
    matrix B = POWW(A, n-2);
    cout << (B.val[1][1] * 2 + B.val[1][2] + B.val[1][3]) % M;
}

// 0 1 1 2 3 5 8
