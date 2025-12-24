#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define fileName "find"
#define pb push_back
#define vll vector<long long>
const ll N = 1e6+7;
ll n;
vll x;
string kq = "";
bool ok;
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
    cin >> n;
    if (n == 0) cout << 10;
    else {
        while (n > 1){
            ok = false;
            for (int i = 9; i >=2; i--){
                if (n % i == 0){
                    ok = true;
                    kq += to_string(i);
                    n /= i;
                    break;
                }
            }
            if (!ok){
                kq = "1-";
                break;
            }
        }
        reverse(kq. begin(), kq.end());
        cout << kq;
    }
}
int main(){
    Start();
    Solve();
    return 0;
}