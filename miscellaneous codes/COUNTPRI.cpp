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
#define fileName "COUNTPRI"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6+7;
bool f[N+1];
ll n, cnt[N];
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
    ll l,r; cin>>l>>r;
    cout<<cnt[r]-cnt[l-1]<<el;
}
int main()
{
    Start();
    f[0]=f[1]=0;
    for (int i=2; i<=N; i++) f[i]=1;
    for (int i=2; i*i<=N; i++){
        if (f[i]){
            for (int j=i*i; j<=N; j+=i){
                f[j]=0;
            }
        }
    }
    cnt[0]=0;
    for (int i=1; i<=N; i++){
        if (f[i]) cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1];
    }
    ll t; cin>>t; while (t--) Solve();
}