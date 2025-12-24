#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int seg[4*N];
bool ok[N];
void INSERT(int id,int l,int r,int x)
{
    if(l>x or r<x) return;
    if(l==x and r==x)
    {
        seg[id]++;
        ok[x]=true;
        return;
    }
    int mid=(l+r)/2;
    INSERT(2*id,l,mid,x);
    INSERT(2*id+1,mid+1,r,x);
    seg[id]=seg[2*id]+seg[2*id+1];
}
void DELETE(int id,int l,int r,int x)
{
    if(l>x or r<x) return;
    if(l==x and r==x)
    {
        seg[id]--;
        ok[x]=false;
        return;
    }
    int mid=(l+r)/2;
    DELETE(2*id,l,mid,x);
    DELETE(2*id+1,mid+1,r,x);
    seg[id]=seg[2*id]+seg[2*id+1];
}
int COUNT(int id,int l,int r,int x)
{
    if(x<l) return 0;
    if(1<=l and r<=x) return seg[id];
    int mid=(l+r)/2;
    return COUNT(2*id,l,mid,x)+COUNT(2*id+1,mid+1,r,x);
}
int KTH(int id,int l,int r,int remain)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    if(seg[2*id]>=remain) return KTH(2*id,l,mid,remain);
    else return KTH(2*id+1,mid+1,r,remain-seg[2*id]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        int x;
        cin >> s >> x;
        if(s=="INSERT")
        {
            if(!ok[x]) INSERT(1,1,1e6,x);
        }
        else if(s=="DELETE")
        {
            if(ok[x]) DELETE(1,1,1e6,x);
        }
        else if(s=="COUNT")
        {
            cout << COUNT(1,1,1e6,x-1) << "\n";
        }
        else
        {
            if(COUNT(1,1,1e6,1e6)<x) cout << -1 << "\n";
            else cout << KTH(1,1,1e6,x) << "\n";
        }
    }
    return 0;
}
