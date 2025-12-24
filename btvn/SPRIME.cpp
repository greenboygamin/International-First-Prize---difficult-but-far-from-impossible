#include<bits/stdc++.h>
#define ll long long
using namespace std;
void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("SPRIME.inp", "r")) {
        freopen("SPRIME.inp", "r", stdin);
        freopen("SPRIME.out", "w", stdout);
    }
}

void gen(vector<bool>& check) {
    int limit = 10000000;
    vector<bool> isprime(limit + 1, true);
    isprime[0] = isprime[1] = false;
    for (int p = 2; p * p <= limit; ++p) {
        if (isprime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isprime[i] = false;
            }
        }
    }
    for (int i = 2; i <= limit; ++i) {
        if (!isprime[i]) continue;
        int num = i;
        bool isp = true;
        while (num > 0) {
            if (!isprime[num]) {
                isp = false;
                break;
            }
            num /= 10;
        }
        if (isp) check[i] = true;
    }
}
void Solve() {
    ll l, r;
    cin >> l >> r;
    vector<bool> check(10000001, false);
    gen(check);
    for (int i = l; i <= r; ++i) {
        if (check[i]) cout << i << '\n';
    }
}
int main() {
    Task();
    Solve();
    return 0;
}
