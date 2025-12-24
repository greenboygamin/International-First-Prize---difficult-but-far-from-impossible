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
#define fileName ""
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e4;
ll a, b, c, t;
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
    ll mins = INT_MAX;
    cin >> a >> b >> c;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j+=i)
        {
            for (int z = j; z <= N; z+=j) mins = min(mins, abs(a-i) + abs(b-j) + abs(c-z));
        }
    }
    cout << mins << el;
}

int main()
{
    Start();
    cin >> t; while (t--) Solve();
}
