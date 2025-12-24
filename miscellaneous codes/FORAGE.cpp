#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll p,n,k,p1;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("FORAGE.inp", "r")) {
        freopen("FORAGE.inp", "r", stdin);
        freopen("FORAGE.out", "w", stdout);
    }
}
void Solve() {
    cin>>p>>n>>k;
    p1=(((n+1)*n)/2)*k;

    if (p>=p1) cout<<"YES";
    else cout<<"NO"<<'\n'<<p1-p;
}
int main(){
    Task();
    Solve();
    return 0;
}