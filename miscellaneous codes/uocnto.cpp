#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
const ll N = 1e6 + 7;
using namespace std;

ll a, b, c[N], cnt[N];
bool p[N];

void Start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen("uocnto.inp", "r")) {
        freopen("uocnto.inp", "r", stdin);
        freopen("uocnto.out", "w", stdout);
    }
}

ll demuoc(ll n) {
    ll k, d = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            k = 0;
            while (n % i == 0) {
                k++;
                n /= i;
            }
            d *= (k + 1);
        }
    }
    if (n > 1) d *= 2;
    return d;
}

void Solve() {
    cin >> a >> b;
    cout << cnt[b] - cnt[a - 1] << el;
}

int main() {
    Start();
    fill(p, p + N, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (p[i]) {
            for (int j = i * i; j < N; j += i) {
                p[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        ll num_divisors = demuoc(i);
        if (num_divisors < N && p[num_divisors]) {
            c[i] = 1;
        }
        cnt[i] = cnt[i - 1] + c[i];
    }

    ll t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
