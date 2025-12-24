//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "depart"
#define maxn 1002
#define MOD 1000000007
#define remain(x) if (x >= MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string s, X;
int f[100005], n;

struct Tries
{
    bool isend;
    Tries *child[26];	
    Tries()
    {
        isend = false;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

Tries T;

void read()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        Tries *p = &T;
        for (int i = 0; i < s.length(); i++)
        {
            int ch = s[i] - 97;
            if (p->child[ch] == NULL) p->child[ch] = new Tries();
            p = p->child[ch];
        }
        p->isend = true;
    }
    cin >> s;
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void dp()
{
    f[0] = 1;
    int m = s.length();
    s = " " + s;
    for (int i = 0; i < m; i++)
    {

        Tries *p = &T;
        for (int j = i+1; j <= m; j++)
        {
            int ch = s[j] - 97;
            if (p->child[ch] == NULL) break;
            p = p->child[ch];
            if (p->isend) add(f[j], f[i]); 
        }
    }
    //for (int i = 1; i <= m; i++) cout << f[i] << endl;
    cout << f[m];
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    read();
    dp();
    return 0;
}
