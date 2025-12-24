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
#define fileName "tile"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6+7;
ll n, s, x[N], y[N];
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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + n + 1);
    ll d = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d <= x[i]) d++;
    }
    cout << d;
}
int main()
{
    Start();
    Solve();
}
