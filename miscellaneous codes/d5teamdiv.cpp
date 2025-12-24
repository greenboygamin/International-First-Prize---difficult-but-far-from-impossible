#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<int, int>> vpii;
typedef vector<int> vi;
typedef vector<long long> vll;
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
const ll MOD = 2e18;

int t, n;

struct lucky{
    ll val, id, len;
};

bool cmp(const lucky &quan, const lucky &ki){
    return quan.val < ki.val;
}

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
    vector<lucky> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a.begin() + 1, a.begin() + n + 1, cmp);
    for (int i = 1; i <= n; i++){
        a[i].len = 1;
        for (int j = 1; j < i; j++){
            if (a[i].val % a[j].val == 0){
                a[i].len = max(a[i].len, a[j].len + 1);
            }
        }
    }
    vll odds, evens;
    for (int i = 1; i <= n; i++){
        if (a[i].len % 2 != 0) odds.pb(a[i].id);
        else evens.pb(a[i].id);
    }
    if (odds.size() < evens.size()){
        cout << odds.size() << " ";
        for (auto &x : odds) cout << x << " ";
    }
    else {
        cout << evens.size() << " ";
        for (auto &x : evens) cout << x << " ";
    }
    cout << el;
}

int main() {
    tassk(); cin >> t; while (t--) 
    solve();
    return 0;
}
 