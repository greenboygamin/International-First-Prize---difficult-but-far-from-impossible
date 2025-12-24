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
#define Task "foundstr"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, cnt = 0;
bool Isend[500001];// đỉnh có phải kết thúc 1 xâu hay không
int Child[500001][26];

void Add (string s){
    int node = 0;
    for (char c : s){
        int x = c - 'a'; // a -> 0; b -> 1; c -> 2; ...
        if (Child[node][x] == 0) Child[node][x] = ++cnt;
        node = Child[node][x]; // đi vào nhánh con
    }
    Isend[node] = 1;
}

bool Found(string s){
    int node = 0;
    for (char c: s){
        int x = c - 'a';
        if (Child[node][x] == 0) return 0; // không có xâu
        node = Child[node][x];
    }
    return Isend[node];
}

int main()
{
	ios_base::sync_with_stdio(0);
    //freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        Add(s);
    }
    cin >> m;
    while (m--){
        string s;
        cin >> s;
        cout << Found(s) << "\n";
    }

    return 0;
}

