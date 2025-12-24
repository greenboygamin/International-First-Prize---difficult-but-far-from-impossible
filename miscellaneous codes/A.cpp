#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
int n, a[N], tr[N], sau[N];
stack<ll> s;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
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
    a[0] = a[n + 1] = 2e9;
    s.push(0);
    ll dem = 0;
    for (int i = 1; i <= n; i++){
        while (!s.empty() && a[i] >= a[s.top()]) s.pop();
        tr[i] = s.top();
        s.push(i);
    }
    while (s.size()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; i--){
        while (!s.empty() && a[i] >= a[s.top()]) s.pop();
        if (s.top() == n + 1) sau[i] = 0;
        else sau[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++){
        cout << tr[i] << " " << sau[i] << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
 