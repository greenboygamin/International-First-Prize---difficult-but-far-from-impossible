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
#define fileName "EQUAL"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6 + 1;
ll m, n, a[N];
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
void Solve() {
    cin >> n;
    unsigned ll int ans = 1e18 + 1;
    unsigned ll int t = 0, s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t += a[i] * a[i];
        s += a[i];
    }
    for (int i = -N; i <= N; i++)
    {
        ans = min(ans, t - 2 * i * s + n * i * i);
    }
    cout << ans;
}
int main()
{
    Start();
    Solve();
    return 0;
}
