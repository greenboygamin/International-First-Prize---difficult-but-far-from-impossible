//Dai Ca Di Hoc
// Tìm nhị phân, check lại hoặc dùng 2 mã băm để loại giảm xác suất sai
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "adn"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>


using namespace std;

const int base = 131;
const long long MOD2 = 1ll * MOD * MOD;

int n, ans = 0;
string X, Y, ansX, ansY;

pii a[maxn];
int resx, resy;

long long PW[maxn], SX[maxn], SY[maxn];

void Init(){
    PW[0] = 1;
    for (int i = 1; i <= n+n; i++) PW[i] = (PW[i-1] * base) % MOD;
}

void Make_Hash(string &s, long long sum[]){
    sum[0] = 0;
    for (int i = 1; i <= n+n; i++)
        sum[i] = (sum[i-1] * base + s[i]) % MOD;
}

int Get_Hash_X(int L, int R){
    return (MOD2 + SX[R] - SX[L-1] * PW[R-L+1]) % MOD;
}

int Get_Hash_Y(int L, int R){
    return (MOD2 + SY[R] - SY[L-1] * PW[R-L+1]) % MOD;
}

bool check(int len){
    for (int i = 1; i <= n; i++)
        a[i] = mp(Get_Hash_X(i, i+len-1) , i);
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        int val = Get_Hash_Y(i, i+ len - 1);
        int pos = lower_bound(a+1, a+n+1, mp(val, 0)) - a;
        while (a[pos].F == val & pos <= n)
        {
            if (X.substr(a[pos].S, len) == Y.substr(i,len)){
                resx = a[pos].S + len;
                resy = i + len;
                return 1;
            }
            pos++;
        }
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
    cin >> X >> Y;
    n = X.length();
    X = " " + X + X; Y = " " + Y + Y;
    Init();
    Make_Hash(X, SX);
    Make_Hash(Y, SY);
    int L = 0, R = n+1;
    resx = resy = 1;
    while (R - L > 1){
        int mid = (L+R)/2;
        if (check(mid)) L = mid;
            else R = mid;
    }
    cout << L << endl;
//    if (resx <= n+1) resx += n;
//    if (resy <= n+1) resy += n;
//    cout << X.substr(resx - n, n) << endl;
//    cout << Y.substr(resy - n, n) << endl;
    return 0;
}

