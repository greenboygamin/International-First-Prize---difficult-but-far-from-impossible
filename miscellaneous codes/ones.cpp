#include <bits/stdc++.h>
using namespace std;
#define task "ones"
const long long N=1e6+10;
long long ans,isprim[N],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    for(long long i=2;i*i<=N;i++)
    {
        if(isprim[i]==0)
        {
            for(long long j=i*i;j<=N;j+=i)
            {
                if(isprim[j]==0) isprim[j]=i;
            }
        }
    }
    long long t;
    cin >> t;
    while(t--)
    {
        map <long long,long long> mp;
        cin >> n;
        for(long long i=1;i<=n;i++)
        {
            long long x,cnt=1,dem=0,bef=-1;
            cin >> x;
            while(true)
            {
                if(x==1) break;
                if(isprim[x]==0)
                {
                    if(bef==-1) mp[x]=max(mp[x],1ll);
                    else if(x==bef)
                    {
                        mp[x]=max(mp[x],dem+1);
                    }
                    else 
                    {
                        mp[bef]=max(mp[bef],dem);
                        mp[x]=max(mp[x],1ll);
                    }
                    break;
                }
                if(bef!=-1 and bef==isprim[x])
                {
                    dem++;
                }
                else if(bef!=-1 and bef!=isprim[x])
                {
                    mp[bef]=max(mp[bef],dem);
                    dem=1;
                    bef=isprim[x];
                }
                else 
                {
                    dem++;
                    bef=isprim[x];
                }
                x/=isprim[x];
            }
        }
        ans=0;
        for(auto i:mp)
        {
            ans+=i.second;
        }
        cout << ans;
    }
    return 0;
}