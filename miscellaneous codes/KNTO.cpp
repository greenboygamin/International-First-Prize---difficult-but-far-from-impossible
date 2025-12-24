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
#define fileName "KNTO"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e3  + 5;
ll n;
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
    cin>>n;
    ll d=1, k, ans=0;
    for (ll i=2; i*i<=n; i++){
        if (n%i==0){
            k=0;
            ans++;
            while (n%i==0){
                n/=i;
                k++;
            }
            d*=k+1;
        }
    }
    if (n>1) d*=2, ans++;
    cout<<d-ans;
}
int main()
{
    Start();
    Solve();
}