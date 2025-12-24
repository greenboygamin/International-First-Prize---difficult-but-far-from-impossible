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
#define fileName "phonghop"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e5  + 5;
ll n, a[N], b[N], f[N], t[N], vt[N], s;
using namespace std;
vll v;
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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        vt[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {   
            //a: begin, b: end, c: value
            if (b[i] > b[j])
            {
                swap(a[i], a[j]); swap(b[i],b[j]); swap(vt[i], vt[j]);
            }
        }
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (b[j] <= a[i])
            {
                if (f[i] < f[j] + 1){
                    f[i] = f[j] + 1;
                    t[vt[i]] = vt[j];
                }
            }
        }
    }
    ll maxs = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (maxs < f[i])
        {
            maxs = f[i];
            s = vt[i];
        }
    }
    while (s != 0)
    {
        v.pb(s);
        s = t[s];
    }
    cout << maxs << el;
    reverse(v.begin(), v.end());
    for (auto &i : v) cout << i << " ";
}
int main()
{
    Start();
    Solve();
}