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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 123456789;

int n;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

// ================= TỐI ƯU BIG NUMBER =================

int add(int a, int b) { a += b; if (a >= MOD) a -= MOD; return a; }

int mul(int a, int b) { return 1ll * a * b % MOD; }

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

vector<int> primes, lpf;
void linear_sieve(int n) {
    lpf.resize(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            primes.push_back(i);
            lpf[i] = i;
        }
        for (int p : primes) {
            if (p * i > n || p > lpf[i]) break;
            lpf[i * p] = p;
        }
    }
}

int m;

struct Num {
    vector<int> coef;
    Num() { coef.assign(m, 0); }
    Num(int x) {
        coef.assign(m, 0);
        for (int i = 0; i < m; i++)
            while (x % primes[i] == 0)
                coef[i]++, x /= primes[i];
    }
    int decode() {
        int res = 1;
        for (int i = 0; i < m; i++)
            res = mul(res, power(primes[i], coef[i]));
        return res;
    }
    Num operator * (const Num& other) const {
        Num res;
        for (int i = 0; i < m; i++)
            res.coef[i] = coef[i] + other.coef[i];
        return res;
    }
    Num operator / (const Num& other) const {
        Num res;
        for (int i = 0; i < m; i++)
            res.coef[i] = coef[i] - other.coef[i];
        return res;
    }
    Num GCD(const Num& a, const Num& b) const {
        Num res;
        for (int i = 0; i < m; i++)
            res.coef[i] = min(a.coef[i], b.coef[i]);
        return res;
    }
};

// ================= CHƯƠNG TRÌNH CHÍNH =================

void solve() {
    cin >> n;

    linear_sieve(200);
    m = primes.size();

    stack<Num> s;
    vector<int> input(3 * n + 2);

    for (int i = 1; i <= 3 * n + 1; i++) {
        cin >> input[i];
    }

    reverse(input.begin() + 1, input.begin() + 3 * n + 2);

    for (int i = 1; i <= 3 * n + 1; i++) {
        if (input[i] == -1) {
            s.push(Num());  // push rỗng (đơn vị)
        } else {
            int x = input[i + 1], y = input[i];
            i++;
            Num u = s.top(); s.pop();
            Num v = s.top(); s.pop();
            Num p = Num(x), q = Num(y), sum = Num(x + y);
            Num gcd; gcd = gcd.GCD(p * u, q * v);
            s.push(u * v * sum / gcd);
        }
    }

    cout << s.top().decode() << '\n';
}

int main() {
    tassk();
    solve();
    return 0;
}
