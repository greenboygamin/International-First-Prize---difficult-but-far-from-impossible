#include <bits/stdc++.h>
using namespace std;

#define task "domine"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 5e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 998244353;

int r, c, k;
int a[M][M], d[N], inq[N], par[N];
int idx[M][M];
vi L, R;
vi adj[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

struct edge{
    int u, v, cap, cost;
}; vector<edge> edges;

void addEdge(int u, int v, int cap, int cost){

}

bool spfa(){

}

void mcmf(){

}

void Solve(){
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            idx[i][j] = ++cnt;
            if ((i & 1) == (j & 1)){
                L.pb(idx[i][j]);
            }
            else{
                R.pb(idx[i][j]);
            }
        }
    }
}

int main() {
    Task();
    Solve();
    return 0;
}
