//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 1000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "lookup"

using namespace std;

typedef long long ll;
typedef long double ld;

int pass[maxn], res[maxn], cnt = 0, n;
int Child[maxn][26];
map <string, int> M;

int Add(string &s){
    int sum = 0, node = 0;
    for (char c : s){
        int x = c - 'a';
        if (Child[node][x] == 0) Child[node][x] = ++ cnt;
        node = Child[node][x];
        pass[node]++;
        sum += pass[node];
    }
    return sum;
}

int Found(string &s){
    int sum = 0, node = 0;
    for (char c : s){
        int x = c - 'a';
        if (Child[node][x] == 0) Child[node][x] = ++ cnt;
        node = Child[node][x];
        sum += pass[node];
    }
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s; cin >> s;
        res[i] = Add(s) + i;
        if (M[s] == 0) M[s] = i;
    }
    int q;
    cin >> q;
    while (q--){
        string s; cin >> s;
        if (M[s] == 0) cout << Found(s) + n << "\n";
            else cout << res[M[s]] << "\n";
    }
    return 0;
}

