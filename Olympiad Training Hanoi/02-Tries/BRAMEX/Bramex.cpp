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
#define Task "bramex"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, cnt = 0;
string s[maxn];
int Next[1000001][10], num[1000001];

struct data{
    int id, pos;
    string st;
};
data a[maxn];

void Add(string st){
    int node = 0, sum = 0;
    for (char c : st){
        //char ch = c > 90 ?   c - 'a' + 26: c - 'A';
        char ch = c - 'a';
        if (Next[node][ch] == 0) Next[node][ch] = ++cnt;
        node = Next[node][ch];
        ++num[node];
    }
}

int Get(string st){
    int node = 0;
    for (char c : st){
        //char ch = c > 90 ?   c - 'a' + 26: c - 'A';
        char ch = c - 'a';
        if (Next[node][ch] == 0) return 0;
        node = Next[node][ch];
    }
    return num[node];
}


int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        Add(s[i]);
    }
    cin >> m;
    string st;
    for (int i = 1; i <= m; i++){
        cin >> st;
        cout << Get(st) << '\n';
    }
    return 0;
}

