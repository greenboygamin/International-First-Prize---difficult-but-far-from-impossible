#include <bits/stdc++.h>
using namespace std;
#define task "phantich"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue
const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
ll n;
vll cur;
vector<vll> sol;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".INP", "r")) {
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
}

void np(ll ans, ll mins) {
    if (ans == 0) {
        sol.pb(cur);
        return;
    }
    for (int i = mins; i <= ans; ++i) {
        cur.pb(i);
        np(ans - i, i);
        cur.pop_back();
    }
}

void solve() {
    cin >> n;
    np(n, 1);
    for (auto &i : sol) {
        cout << n << "=";
        for (int j = 0; j < i.size(); ++j) {
            if (j > 0) cout << "+";
            cout << i[j];
        }
        cout << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
