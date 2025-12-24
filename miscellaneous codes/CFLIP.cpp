#include <bits/stdc++.h>
using namespace std;

#define task "CFLIP"
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
const ll INF = 1e18;
const ll MOD = 123456789;

int q;
int n;
vector<int> t;
int st[26][N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    memset(st, 0, sizeof st);
    for (int i = 0; i < 2 * n; i++) st[0][i] = 2 * t[i] - i;
    for (int i = 1; i < 26; i++){
        for (int j = 0; j + (1 << i) < 2 * n; j++){
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int get(int l, int r){
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    t.assign(2 * n + 1, 0);
    s = s + s;
    t[0] = (s[0] == 'T');
    for (int i = 1; i < 2 * n; i++) t[i] = t[i - 1] + (s[i] == 'T');
    int mini = INT_MAX, mink = INT_MAX;
    init();
    for (int i = 0; i < n; i++){
        int res = i + n - t[i] - t[i + n];
        for (int k = i; k <= i + n; k++){
            mink = min(mink, 2 * t[k] - k);
        }
        mini = min(mini, res + mink);
    }
    cout << mini << el;
}

int main() {
    tassk(); cin >> q;
    while (q--) solve();
    return 0;
}   