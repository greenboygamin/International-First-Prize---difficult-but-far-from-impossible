#include <bits/stdc++.h>
using namespace std;

#define task "SUBSTR"
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

const ll N = 2e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 4e18;

string s, t;
int n, m;
int nxt[N][26];
bool ex[26];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> s >> t;
    n = s.size(); m = t.size();
    for (int i = 0; i < n; i++) ex[s[i] - 'a'] = 1;
    for (int i = 0; i < m; i++) if (!ex[t[i] - 'a']){
        cout << -1 << el;
        return;
    }
    for (int i = 0; i < 26; i++){
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; i--){
        for (int c = 0; c < 26; c++){
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    ll loops = 0, i = 0;
    for (int j = 0; j < m; j++){
        int c = t[j] - 'a';
        int k = nxt[i][c];
        if (k == n){
            loops++;
            i = 0;
            k = nxt[0][c];
        }
        i = k + 1;
    }
    ll ans = loops * n + i;
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}