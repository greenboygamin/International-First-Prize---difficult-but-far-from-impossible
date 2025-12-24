#include <bits/stdc++.h>
using namespace std;
bool check(int n) {
    if (n<=1) return false;
    if (n<=3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int tach(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("DOCAO.inp", "r")) {
        freopen("DOCAO.inp", "r", stdin);
        freopen("DOCAO.out", "w", stdout);
    }
}

void Solve() {
    int n, h;
    cin >> n >> h;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (tach(i) == h && check(i)) {
            cout << i << endl;
            count++;
        }
    }
    cout << count;
}

int main() {
    Task();
    Solve();
    return 0;
}
