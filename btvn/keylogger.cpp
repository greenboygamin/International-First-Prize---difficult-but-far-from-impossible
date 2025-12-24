#include <bits/stdc++.h>
using namespace std;
#define task "keylogger"
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
string s;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void solve() {
    cin >> s;
    deque<char> deq;
    auto id = deq.begin();
    for (auto ch : s){
        if (ch == '-'){
            if (id != deq.begin()) id = deq.erase(prev(id));
        } 
        else if (ch == '<'){
            if (id != deq.begin()) id--;
        }
        else if (ch == '>'){
            if (id != deq.end()) id++;
        }
        else {
            id = deq.insert(id, ch);
            id++;
        }
    }
    for (auto i : deq) cout << i;
}

int main() {
    tassk();
    solve();
    return 0;
}
