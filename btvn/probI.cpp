#include <bits/stdc++.h>
using namespace std;

#define task ""
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
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

pii a[N];
int n, m, k;
set<pii> bag;
set<int> sack;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--){
        if (bag.size() == k) break;
        bag.insert(a[i]);
        sack.insert(a[i].first);
    }
    vector<pii> b(bag.begin(), bag.end());
    reverse(b.begin(), b.end());
    for (int i = 1; i <= m - (k - 1); i++) cout << b[0].second << " ";
    for (int i = 1; i < b.size(); i++) cout << b[i].second << " ";
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 