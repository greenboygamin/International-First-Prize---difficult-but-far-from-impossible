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
#define Task "PAROLE"
#define maxn 3000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string A, B;
int n, m;

const int Base = 131;
const long long MM = 1ll * MOD * MOD;

long long H[maxn], S[maxn], T[maxn];

long long Get_N(int L, int R)
{
    return (T[L] + MM - T[R+1] * H[R-L+1]) % MOD;
}

string Calc(string A)
{
    A = " " + A;
    S[0] = 0;
    for (int i = 1; i <= n; i++) S[i] = (S[i-1] * Base + A[i]) % MOD;
    T[n+1] = 0;
    for (int i = n; i >= 1; i--) T[i] = (T[i+1] * Base + A[i]) % MOD;
    for (int i = n; i >= 1; i--)
        if (S[i] == Get_N(1,i)){ //S[i] = Get_hash(1,i)
            string duoi = A.substr(i+1, n-i);
            reverse(duoi.begin(), duoi.end());
            return duoi + A.substr(1,n);
        }
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> A;
    n = A.length();
    H[0] = 1;
    for (int i = 1; i <= n; i++) H[i] = (H[i-1] * Base) % MOD;

    string res1 = Calc(A);
    reverse(A.begin(), A.end());
    string res2 = Calc(A);
    cout << ((res1.length() < res2.length()) ? res1 : res2);
    return 0;
}
