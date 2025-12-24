#include <bits/stdc++.h>
using namespace std;

#define task "FREEBUS"
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
const ll MOD = 1e9 + 7;
vll power31, hash1;
string s;
ll n;
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    power31.resize(n + 1, 1);
    hash1.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        power31[i] = (power31[i - 1] * 31) % MOD;
        hash1[i] = (hash1[i - 1] * 31 + (s[i - 1] - 'a' + 1)) % MOD;
    }
}

int get(int l, int r){
    int len = r - l + 1;
    return (hash1[r] - hash1[l - 1] + MOD % MOD) % MOD;
}

void solve() {
    cin >> s; n = s.size();
}

int main() {
    tassk();
    solve();
    return 0;
}