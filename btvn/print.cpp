#include <bits/stdc++.h>
using namespace std;
#define task "print"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n, m;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m;
    vpll v;
    pq<ll> kiu;
    ll x, time = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        kiu.push(x);
        v.push_back({x, i});
    }
    while (!v.empty()){
        pll tmp = v.front();
        v.erase(v.begin());
        if (tmp.first == kiu.top() && !kiu.empty()){
            time += 60;
            kiu.pop();
            if (tmp.second == m){
                cout << time / 60 << " " << time % 60 << el;
                return;
            }
        }
        else {
            v.pb(tmp);
            time += 1;
        }
    }
}

int main() {
    tassk();
    ll t; 
    cin >> t; 
    while (t--) solve();
    return 0;
}