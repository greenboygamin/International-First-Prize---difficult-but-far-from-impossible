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
#define fileName "chiakeo"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6  + 5;
ll n=0,a[N],f[N],vt[N],s=0;
bool kt[N];
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

int main()
{
    Start();
    ll n; cin>>n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    f[0]=1;
    for (int i=1; i<=n; i++){
        for (int j=s/2-a[i]; j>=0; j--){
            if (f[j]==1&&f[j+a[i]]==0){
                f[j+a[i]]=1;
                vt[j+a[i]]=i; // 
            }
        }
    }
    ll i=s/2;
    while (f[i]==0) i--;
    cout<<s-i*2<<endl;
    vector<ll> ans;
    while (i>0){
        kt[vt[i]]=1;
        ans.pb(vt[i]);
        i=i-a[vt[i]];
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    return 0;
}