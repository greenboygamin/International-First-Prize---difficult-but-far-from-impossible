#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define el "\n"
#define fileName "milk"
#define pb push_back
const ll N = 1e6+7;
int n, m, p[N], a[N], value[N], s = 0;
void Start(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(fileName".inp","r")){
        freopen(fileName".inp","r",stdin);
        freopen(fileName".out","w",stdout);
    }
}

struct sua {ll gia; ll tri;} buy[N];
bool ss(const sua &a, const sua &b){
    return a.gia <= b.gia;
}
void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> p[i] >> a[i];
        buy[i].gia = p[i];
        buy[i].tri = a[i];
    }
    sort (buy + 1, buy + m + 1, ss);
    ll dem = 0, cost = 0;
    for (int i = 1; i <= m; i++){
        if (dem + buy[i].tri > n){
            cost += buy[i].gia * (n - dem);
            break;
        }
        else {
            cost += buy[i].tri * buy[i].gia;
            dem += buy[i].tri;
        }
    }
    cout << cost << el;
    //for (int i = 1; i <= m; i++) cout << value[i] << " ";
}
int main(){
    Start();
    Solve();
    return 0;
}