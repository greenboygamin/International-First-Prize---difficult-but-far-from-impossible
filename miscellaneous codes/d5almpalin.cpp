#include <bits/stdc++.h>
using namespace std;
#define task "almpalin"
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

ll p10[20];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    p10[0] = 1;
    for (int i = 1; i <= 18; i++) p10[i] = p10[i - 1] * 10;
}

ll count_full(int len) {
    if (len == 1) return 9;
    int k = len / 2;
    ll ans = 9 * p10[(len + 1) / 2 - 1]; 
    ll w1 = 81 * p10[k - 1]; 
    if (len % 2 == 1) w1 *= 10;
    ans += w1;
    if (k > 1) {
        ll w2 = (k - 1) * 9 * 90;
        if (k > 2) w2 *= p10[k - 2];
        if (len % 2 == 1) w2 *= 10;
        ans += w2;
    }
    return ans;
}

ll get_ways(int len, vector<int> &p) {
    int k = len / 2;
    int cnt = 0, unk = 0, fr = 0;
    int psz = p.size();
    
    for (int i = 0; i < k; i++) {
        int j = len - 1 - i;
        if (j < psz) {
            if (p[i] != p[j]) cnt++;
        } else if (i < psz) {
            unk++;
        } else {
            fr++;
        }
    }
    
    if (cnt > 1) return 0;
    int rem = 1 - cnt;
    
    ll ways = 0;
    ll w0 = p10[fr];
    ways += w0; 
    
    if (rem == 1) {
        if (unk > 0) ways += unk * 9 * p10[fr];
        if (fr > 0) ways += fr * 90 * p10[fr - 1];
    }
    
    if (len % 2 == 1) {
        if (len / 2 >= psz) ways *= 10;
    }
    
    return ways;
}

ll calc(string s) {
    int n = s.length();
    ll ans = 0;
    for (int i = 1; i < n; i++) ans += count_full(i);
    vector<int> d;
    for (char c : s) d.pb(c - '0');
    
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int lim = d[i];
        int start = (i == 0) ? 1 : 0;
        for (int dig = start; dig < lim; dig++) {
            p.pb(dig);
            ans += get_ways(n, p);
            p.pop_back();
        }
        p.pb(lim);
    }
    
    int mm = 0;
    for (int i = 0; i < n / 2; i++) {
        if (d[i] != d[n - 1 - i]) mm++;
    }
    if (mm <= 1) ans++;
    
    return ans;
}

void solve() {
    string s;
    while (cin >> s && s != "0") {
        cout << calc(s) << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}