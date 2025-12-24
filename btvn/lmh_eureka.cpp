#include <bits/stdc++.h>
using namespace std;

#define task "lmh_eureka"
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

int n;
vector<int> lpf;
vector<int> inp;
vector<int> primes;


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void sieve(int n){
    lpf.assign(n + 1, 0);
    for (int i = 2; i <= n; i++){
        if (lpf[i] == 0){
            primes.pb(i);
            lpf[i] = i;
        }
        for (int p : primes){
            if (p * i > n || p > lpf[i]) continue;
            lpf[i * p] = p;
        }
    }
}

ll add(ll a, ll b){
    a += b; if (a > MOD) a -= MOD; return a;
}

ll sub(ll a, ll b){
    a -= b; if (a <= 0) a += MOD; return a;
}

ll mul(ll a, ll b){
    return 1LL * a * b % MOD;
}

ll powmod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int m;

struct Num{
    vector<int> coef;
    Num(){
        coef.assign(m + 1, 0);
    }
    Num(int x){
        coef.assign(m + 1, 0);
        for (int i = 0; i < m; i++){
            while (x % primes[i] == 0){
                coef[i]++;
                x /= primes[i];
            }
        }
    }
    int decode(){
        ll res = 1;
        for (int i = 0; i < m; i++){
            res = mul(res, powmod(primes[i], coef[i]));
        }
        return res;
    }
    Num operator* (const Num& other) const{
        Num res;
        for (int i = 0; i < m; i++){
            res.coef[i] = coef[i] + other.coef[i];
        }
        return res;
    }
    Num operator/ (const Num& other) const{
        Num res;
        for (int i = 0; i < m; i++){
            res.coef[i] = coef[i] - other.coef[i];
        }
        return res;
    }
    Num GCD (const Num& a, const Num& b) const{
        Num res;
        for (int i = 0; i < m; i++){
            res.coef[i] = min(a.coef[i], b.coef[i]);
        }
        return res;
    }
};

void solve() {
    cin >> n;
    sieve(200);
    m = primes.size();
    inp.resize(3 * n + 2);
    for (int i = 1; i <= 3 * n + 1; i++){
        cin >> inp[i];
    }
    reverse(inp.begin() + 1, inp.begin() + 3 * n + 2);
    stack<Num> s;
    //for (int i = 1; i <= 3 * n + 1; i++) cout << inp[i] << " ";
    for (int i = 1; i <= 3 * n + 1; i++){
        if (inp[i] == -1) s.push(Num());
        else {
            int x = inp[i + 1], y = inp[i];
            i++;
            Num p = Num(x); Num q = Num(y); Num sums = Num(x + y);
            Num a = s.top(); s.pop(); Num b = s.top(); s.pop();
            Num ucln; ucln = ucln.GCD(a * p, b * q);
            s.push((a * b * sums) / ucln);
        }
        //(p * q * (A + B)) / gcd(Ap, Bq);
    }
    cout << s.top().decode();
}

int main() {
    tassk(); 
    solve();
    return 0;
}   