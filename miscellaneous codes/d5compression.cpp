#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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

int m, n;
vector<string> a(N);

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        string s; cin >> s;
        s = " " + s;
        a[i] = s;
    }
    int h = m;
    for (int i = 2; i <= m; i++){
        bool diff = false;
        for (int j = 1; j <= n; j++){
            if (a[i][j] != a[i - 1][j]){
                diff = true;
                break;
            }
        }
        if (diff){
            h = __gcd(h, i - 1);
        }
    }
    int w = n;
    for (int j = 2; j <= n; j++){
        bool diff = false;
        for (int i = 1; i <= m; i++){
            if (a[i][j] != a[i][j - 1]){
                diff = true;
                break;
            }
        }
        if (diff){
            w = __gcd(w, j - 1);
        }
    }
    int mm = m / h;
    int nn = n / w;
    cout << mm << " " << nn << el;
    for (int i = 1; i <= mm; i++){
        for (int j = 1; j <= nn; j++){
            cout << a[i * h][j * w];
        }
        cout << el;
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 