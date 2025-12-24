#include <bits/stdc++.h>
using namespace std;

#define task "removepalin"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;

const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int cost(char a, char b) {
    int d = abs(a - b);
    return min(d, 26 - d);
}

void solve() {
    
}

int main() {
    tassk();
    solve();
    return 0;
}