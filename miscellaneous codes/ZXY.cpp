#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const lli inf=1e11+7, N=1e6+7;
lli n,k,arr[N];
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("ZXY.inp", "r")) {
        freopen("ZXY.inp", "r", stdin);
        freopen("ZXY.out", "w", stdout);
    }
}
bool check(lli x){
    lli d=1, t=0;
    for (int i=1; i<=n; i++){
        if (arr[i]+t>x){
            d++; t=arr[i];
        }
        else t+=arr[i];
    }
    return d<=k;
}
void Solve() {
    cin>>n>>k;
    lli maxs=INT_MIN, s=0;
    for (int i=1; i<=n; i++) cin>>arr[i], maxs=max(maxs,arr[i]), s+=arr[i];
    lli l=maxs, r=s, res;
    while (l<=r){
        lli mid=(l+r)/2;
        if (check(mid)) res=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<res;
}
int main() {
    Task();
    Solve();
    return 0;
}