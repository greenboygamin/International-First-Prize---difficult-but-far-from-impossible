//Dai Ca Di Hoc
// Nhận thấy quy luật 1,2...k sẽ đưa cuối dãy (theo thứ tự hoặc lật ngược)
// k, k+1, ...,n sẽ đưa về đầu dãy
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "beginend"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define B 193939

using namespace std;

int n;
int a[maxn], b[maxn];
long long s1[maxn], t[maxn], s2[maxn], H[maxn];
vector <int> res;

bool dd[maxn];

long long Get(long long s[], int u, int v)
{
    return (1ll * MOD * MOD + s[v] - s[u-1]*H[v-u+1]) % MOD;
}


int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    s1[0] = s2[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s1[i] = (s1[i-1] * B + a[i]) % MOD;
    for (int i = 1; i <= n; i++)
        cin >> b[i], s2[i] = (s2[i-1] * B + b[i]) % MOD;
    t[n+1] = 0;
    for (int i = n; i > 0; i--) t[i] = (t[i+1]*B + b[i]) % MOD;
    H[0] = 1;
    for (int i = 1; i<=n; i++) H[i] = (H[i-1]*B) % MOD;

    for (int k = 1; k <= n; k++)
        if (Get(s1,k,n) == s2[n-k+1])
            if ((n-k)%2 == 1)
            {
                if (s1[k-1] == Get(s2,n-k+2,n)) res.PB(k);
            } else
                if (s1[k-1] == t[n-k+2]) res.PB(k);
                //dd[k] = 1;
    //cout << accumulate(dd+1, dd+n+1, 0) << endl;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";

    return 0;
}

