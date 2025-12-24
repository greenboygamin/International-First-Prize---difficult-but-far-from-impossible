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
#define fileName "WOOD"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6  + 5;
ll n, k, f[N], h[N];
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
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> h[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (i >= h[j]) f[i] = (f[i] + f[i - h[j]]) % MOD;
        }
    }
    cout<<f[n];
}
int main()
{
    Start();
    Solve();
}