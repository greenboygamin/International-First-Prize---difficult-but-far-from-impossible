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
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;
string a, b;
ll n, m;
vll power27, hash_a, hash_b;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void init(){
    power27.resize(n + 1, 1LL);
    hash_a.resize(n + 1, 0LL);
    hash_b.resize(m + 1, 0LL);
    for (int i = 1; i <= n; i++){
        power27[i] = power27[i - 1] * 27;
        hash_a[i] = hash_a[i - 1] * 27 + (a[i - 1] - 'a' + 1);
    }
    for (int i = 1; i <= m; i++){
        hash_b[i] = hash_b[i - 1] * 27 + (b[i - 1] - 'a' + 1);
    }
}

ll get(ll l, ll r, const vll &curhash){
    ll len = r - l + 1;
    return curhash[r] - curhash[l - 1] * power27[len];
}

bool check(ll l, ll r){
    ll cura = get(l, r, hash_a);
    ll curb = get(1, m, hash_b);
    return (cura == curb);
}
void solve() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    init();
    for (int i = 1; i + m - 1 <= n; i++){
        ll j = i + m - 1;
        if (check(i, j)) cout << i << " ";
    }
}

int main() {
    tassk();
    solve();
    return 0;
}