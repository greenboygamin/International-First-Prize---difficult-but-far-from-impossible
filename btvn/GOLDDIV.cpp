#include <bits/stdc++.h>
using namespace std;
#define task "DIVGOLD"
const int N=300,maxval=1e6;
const long long MOD=1e6;
int n,a[N],sum;
long long dp[maxval];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=sum/2;j>=a[i];j--)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%MOD;
        }
    }
    int ans=sum/2;
    while(dp[ans]==0) ans--;
    cout << sum-(ans*2) << "\n" << dp[ans];
    return 0;
}
