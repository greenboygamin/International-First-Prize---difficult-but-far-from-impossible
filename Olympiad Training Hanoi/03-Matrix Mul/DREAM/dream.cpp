//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0, sizeof(x))
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "dream"
#define maxn 102
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

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
        for (int u = 1; u <= 101; u++)
            for (int v = 1; v <= 101; v++)
                for (int i = 1; i <= 101; i++)
                    res.val[u][v] = ((ll)val[u][i] * x.val[i][v] + res.val[u][v] ) % MOD;
        return res;
    }
};

matrix A;
int n, cnt[maxn], dp[maxn];

matrix POWW(matrix A, long long b)
{
    matrix C;
    for (int i = 1; i <= 101; i++) C.val[i][i] = 1;
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}

int main()
{
	ios_base::sync_with_stdio(0);
   // freopen(Task".inp", "r", stdin);
  //  freopen(Task".out", "w", stdout);
    long long x, z;
    reset(cnt);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> z, cnt[z]++;
    for (int i = 2; i <= 101; i++) A.val[1][i] = A.val[2][i] = cnt[i-1];
    for (int i = 3; i <= 101; i++) A.val[i][i-1] = 1;
    A.val[1][1] = 1;
    dp[0] = 1;
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= i; j++) dp[i] = (dp[i] + 1ll * dp[i-j] * cnt[j]) % MOD;
    dp[101] = accumulate(dp, dp+101, 0ll) % MOD;
    if (x <= 100) {
        cout << accumulate(dp, dp+x+1, 0ll) % MOD;
        return 0;}
    A = POWW(A, x-100);
    long long res = 0;
    for (int i = 1; i <= 101; i++) (res += 1ll*dp[i] * A.val[1][102-i]) %= MOD;
    cout << res % MOD;
    return 0;
}


// 0 1 1 2 3 5 8
