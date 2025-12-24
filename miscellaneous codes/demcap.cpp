#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
typedef long long int ll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll INF = 1e9 + 7;
const ll N = 1e6 + 5;
bool isprime[N];
ll t, n, tmp;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool cp(ll n){
    ll chek = sqrt(n);
    return chek * chek == n;
}
void solve() {
    cin >> n;
    if (!cp(n) || n % 16 != 0){
        cout << 0 << el;
        return;
    }
    ll tmp = sqrt(n);
    if (tmp % 4 != 0){
        cout << 2 << el;
        return;
    }
    tmp /= 4;
    ll dem = 0;
    for (int i = 1; i * i <= tmp; i++){
        if (tmp % i == 0){
            dem++;
            if (i * i != tmp) dem++;
        }
    }
    cout << dem << el;
}

int main() {
    tassk();
    cin >> t;
    while (t--)
    solve();
    return 0;
}
