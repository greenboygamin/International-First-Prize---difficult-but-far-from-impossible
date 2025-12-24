#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 500005
#define task "superseq"
#define mod 666013
#define ll long long

using namespace std;

int n, h, k;

struct matrix
{
    long long val[102][102];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }
    matrix operator * (const matrix & x)
    {
        matrix res;
        for (int u = 0; u <= h; u++)
            for (int v = 0; v <= h; v++)
            {
                long long cur;
                cur = res.val[u][v];
                for (int i = 0; i <= h; i++)
                    cur = (ll)val[u][i] * x.val[i][v] + cur;
                cur %= mod;
                res.val[u][v] = cur;
            }
        return res;
    }
} A;

matrix poww(matrix A, int b)
{
    matrix C;
    C.val[0][0] = 1;
    for (; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> h >> k;
    for (int i = 0; i <= h; i++)
        for (int j = 0; j <= h; j++)
            if (abs(i-j) <= k) A.val[i][j] = 1;
                else A.val[i][j] = 0;
    matrix B = poww(A, n-1);
    cout << B.val[0][h] % mod;
    return 0;
}
