
/*#include <bits/stdc++.h>
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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e9 + 7;

// Cấu hình kích thước tối đa cho N=2000
// Số nhát cắt tối đa cho 3x2000 là 3000-1
const int MAX_CUTS = 4005; 
const int MAXN = 2005;

ll fact[MAX_CUTS];
ll invFact[MAX_CUTS];
ll g[MAXN];  // Số cách cho 2 x w
ll dp[MAXN]; // Số cách cho 3 x w

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

// Hàm tính lũy thừa module
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Hàm tính nghịch đảo module
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// Khởi tạo giai thừa
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_CUTS; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

// Tính tổ hợp chập k của n
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Số cách cắt hình 1 x w (chỉ tồn tại khi w chẵn)
// Công thức là (w/2 - 1)!
ll get_h(int w) {
    if (w % 2 != 0) return 0;
    return fact[w / 2 - 1];
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    // Nếu N lẻ, diện tích 3N lẻ, không thể phủ kín bằng domino
    if (n % 2 != 0) {
        cout << 0 << el;
        return;
    }

    // 1. Tính bảng phương án cho hình 2 x i (g[i])
    // Số nhát cắt cho 2 x i là i - 1
    g[1] = 1; // 2x1 là 1 mảnh domino, 0 nhát cắt, 1 cách (không làm gì)

    for (int i = 2; i <= n; ++i) {
        ll ways = 0;
        int total_cuts = i - 1;

        // Trường hợp 1: Cắt ngang (chỉ khi i chẵn) -> tạo thành hai hình 1 x i
        if (i % 2 == 0) {
            int cuts_part = i / 2 - 1; // Số cắt cho 1 x i
            ll ways_h = get_h(i);
            // Chọn thời điểm thực hiện các nhát cắt con trong tổng số (total_cuts - 1) nhát còn lại
            ll term = nCr(total_cuts - 1, cuts_part);
            term = (term * ways_h) % MOD;
            term = (term * ways_h) % MOD;
            ways = (ways + term) % MOD;
        }

        // Trường hợp 2: Cắt dọc tại k (1 <= k < i) -> tạo thành 2xk và 2x(i-k)
        for (int k = 1; k < i; ++k) {
            int cuts_k = k - 1; // Số cắt cho 2 x k
            ll term = nCr(total_cuts - 1, cuts_k);
            term = (term * g[k]) % MOD;
            term = (term * g[i - k]) % MOD;
            ways = (ways + term) % MOD;
        }
        g[i] = ways;
    }

    // 2. Tính bảng phương án cho hình 3 x i (dp[i])
    // Chỉ tính cho i chẵn
    for (int i = 2; i <= n; i += 2) {
        ll ways = 0;
        int total_cuts = 3 * i / 2 - 1;

        // Trường hợp 1: Cắt ngang
        // Có 2 vị trí cắt ngang: giữa dòng 1-2 hoặc giữa dòng 2-3.
        // Cả hai đều chia hình thành (1 x i) và (2 x i).
        int cuts_1xi = i / 2 - 1;
        
        ll ways_1xi = get_h(i);
        ll ways_2xi = g[i];
        
        ll term_horz = nCr(total_cuts - 1, cuts_1xi);
        term_horz = (term_horz * ways_1xi) % MOD;
        term_horz = (term_horz * ways_2xi) % MOD;
        
        // Nhân 2 vì có 2 vị trí cắt ngang
        ways = (ways + 2 * term_horz) % MOD;

        // Trường hợp 2: Cắt dọc tại k (k phải chẵn để các phần con có diện tích chẵn)
        for (int k = 2; k < i; k += 2) {
            int cuts_k = 3 * k / 2 - 1; // Số cắt cho 3 x k
            ll term = nCr(total_cuts - 1, cuts_k);
            term = (term * dp[k]) % MOD;
            term = (term * dp[i - k]) % MOD;
            ways = (ways + term) % MOD;
        }
        dp[i] = ways;
    }

    cout << dp[n] << el;
}

int main() {
    tassk();
    precompute();
    solve();
    return 0;
}*/