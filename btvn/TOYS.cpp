#include <bits/stdc++.h>
using namespace std;

#define task "TOYS"
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

int c[N][26], n, l, r;
string s;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 25; j++) c[i][j] = c[i - 1][j];
        c[i][s[i] - 'a']++;
    }
    ld mins = 1e18;
    l = 1, r = n;
    for (int d = 1; d <= 26; d++){
        int i = 1, j = 1;
        while (j <= n){
            int cnt = 0;
            for (int k = 0; k < 26; k++){
                cnt += (c[j][k] - c[i - 1][k] > 0) ? 1 : 0; 
            }
            if (cnt < d) j++;
            if (cnt > d) i++;
            else {
                int len = j - i + 1;
                ld tmp = (ld) d / (ld) len;
                if (tmp < mins || (abs(tmp - mins) < 1e-12 && l > i)){
                    l = i; r = j;
                    mins = tmp;
                }
                j++;
            }
        }
    }
    cout << l << " " << r;
}


int main() {
    tassk();
    solve();
    return 0;
}