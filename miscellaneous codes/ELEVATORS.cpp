#include <bits/stdc++.h>
#define ll long long
#define ii int
#define pb push_back
#define pob pop_back
#define ld long double
#define pll pair<long long, long long>
#define pii pair<int,int>
#define vll vector<long long>
#define vii vector<int>
#define X first
#define Y second
#define fileName "ELEVATORS"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e5  + 5;
ll n, m, a[N], tng, x, y, t, p;
using namespace std;
void Start(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(fileName".inp","r")){
        freopen(fileName".inp","r",stdin);
        freopen(fileName".out","w",stdout);
    }
}
void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = 1;
    while (m--)
    {
        cin >> tng;
        if (tng == 1) {
            cin >> x;
            a[x] = 0;
        }
        else
        {
            cin >> x >> y;
            t = x; p = x;
            while (a[t] == 1){
                t--;
                if (t == 1) t = n + 1;
            }
            while (a[p] == 1){
                p++;
                if (t == n) t = 0;
            }
        }
    }
}
int main()
{
    Start();
    Solve();
}