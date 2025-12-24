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
#define fileName "gruel"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6+7;
using namespace std;
ll n, m, k;
struct khach {
    ll t, d, a;
}; 
khach x[N];
pq <pii, vector<pii>, greater<pii>> kiu;
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
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        cin >> x[i].t >> x[i].d >> x[i].a;
    }
    cout << "Yes\n";
    kiu.push({x[1].t + x[1].d, x[1].a});
    n--;
    if (x[1].a == 1) m--;
    for (int i = 2; i <= k; i++){
        while(!kiu.empty() && x[i].t >= kiu.top().first){
            n++;
            if (kiu.top().second == 1) m++;
            kiu.pop();
        }
        if (n == 0) cout << "No\n";
        else {
            if (x[i].a == 0){
                n--;
                cout << "Yes\n";
                kiu.push({x[i].t + x[i].d, 0});
            }
            else {
                if (m == 0) cout << "No\n";
                else {
                    m--; n--;
                    cout << "Yes\n";
                    kiu.push({x[i].t + x[i].d, 1});
                }
            }
        }
    }
}
int main()
{
    Start();
    Solve();
    return 0;
}
