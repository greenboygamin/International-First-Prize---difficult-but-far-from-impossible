#include <bits/stdc++.h>
using namespace std;
#define task "TRAIN"
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
ll n, a[N];
queue<ll> kiuc;
queue<ll> kiua;
stack<ll> stab;
vector<string> ans;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) kiuc.push(i);
    ll index = 1;
    while (index <= n){
        if (!kiuc.empty() && kiuc.front() == a[index]){
            kiuc.pop();
            kiua.push(a[index]);
            ans.pb("A->C");
            index++;
        }
        else if (!stab.empty() && stab.top() == a[index]){
            stab.pop();
            kiua.push(a[index]);
            ans.pb("B->C");
            index++;
        }
        else if (!kiuc.empty()){    
            stab.push(kiuc.front());
            kiuc.pop();
            ans.pb("A->B");
        }
        else {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << el;
    for (auto x : ans) cout << x << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
