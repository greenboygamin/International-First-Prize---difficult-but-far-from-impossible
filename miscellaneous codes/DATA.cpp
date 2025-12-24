#include <bits/stdc++.h>
using namespace std;
#define task "DATA"
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
ll n;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    ll k, x;
    queue<ll> q;
    stack<ll> sta;
    pq<ll> kiu;
    bool isq = 1, issta = 1, iskiu = 1;
    while (n--){
        cin >> k >> x;
        if (k == 1){
            if (isq) q.push(x);
            if (issta) sta.push(x);
            if (iskiu) kiu.push(x);
        }
        else if (k == 2){
            if (isq){
                if (q.empty() || q.front() != x) isq = 0;
                else q.pop();
            }
            if (issta){
                if (sta.empty() || sta.top() != x) issta = 0;
                else sta.pop();
            }
            if (iskiu){
                if (kiu.empty() || kiu.top() != x) iskiu = 0;
                else kiu.pop();
            }
        }
    }
    if (isq + issta + iskiu > 1) cout << "no sure" << el;
    else if (isq + issta + iskiu == 0) cout << "impossible" << el;
    else {
        if (isq) cout << "queue" << el;
        else if (issta) cout << "stack" << el;
        else cout << "priority_queue" << el;
    }
}
int main() {
    tassk(); while(cin >> n)
    solve();
    return 0;
}