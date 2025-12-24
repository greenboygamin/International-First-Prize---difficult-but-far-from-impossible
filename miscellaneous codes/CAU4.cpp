#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CAU4"
#define vll vector<long long>
#define pb push_back
const ll N = 1e6 + 7;
const ll M = 1e4 + 7;
string s;
ll vow = 0, cons = 0;
void task(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(TASK".inp", "r")){
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
}
bool isvowel(char x){
    return x == 'u' || x == 'e' || x == 'o' || x == 'a' || x == 'i';
}
void solve(){
    cin >> s;
    ll dem = 0;
    for (int i = 0; i < s.size(); i++){
        if (isvowel(s[i])){
            dem += cons;
            vow++;
        }
        else {
            dem += vow;
            cons++;
        }
    }
    cout << dem;
}

int main(){
    task();
    solve();
    return 0;
}
    // if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i'){
