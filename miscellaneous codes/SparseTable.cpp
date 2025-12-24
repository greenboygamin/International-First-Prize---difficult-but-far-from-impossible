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
const ll INF = 1e18;
const ll MOD = 998244353;

int n, q, a[N], st[26][N], lg[N];


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    for (int i = 2; i < N; i++){
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int i = 1; i < 26; i++){
        for (int j = 1; j + (1 << i) - 1 <= n; j++){
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int get(int l, int r){
    int k = lg[r - l + 1];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << el;
    }
}


int main() {
    tassk();
    solve();
    return 0;
}   