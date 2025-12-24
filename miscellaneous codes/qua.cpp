#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define el "\n"
#define fileName "qua"
#define pb push_back
const ll N = 1e6+7;
ll n, t, small[N], big[N], m;
vector<ll> news;
bool check[N];
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
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> small[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> big[i];
    ll cbig = 0, csmall = 0, dem = 0;
    ll checkpoint, checkpoint2;
    for (int i = 1; i <= n; i++){
        if (csmall + small[i] <= t){
            csmall += small[i];
            checkpoint = i;
            dem++;
        }
    }
    for (int i = 1; i <= m; i++){
        if (cbig + big[i] <= t){
            cbig += big[i];
            dem++;
            checkpoint2 = i;
        }
    }
    if (cbig <= t){
        for (int i = checkpoint + 1; i <= n; i++){
            news.pb(small[i]);
        }
        for (int i = checkpoint2 + 1; i <= m; i++){
            news.pb(big[i]);
        }
        sort(news.begin(), news.end());
        for (int i = 0; i < news.size(); i++){
            if (cbig + news[i] <= t){
                cbig += news[i];
                dem++;
            }
        }
        cout << dem << el;
    }
}
int main(){
    Start();
    Solve();
    return 0;
}