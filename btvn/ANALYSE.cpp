
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,maxs;
int a[100001];
int b[100001];
void readf() {
    int n = 0;
    while (cin >> a[n]) {
        n++;
    }
}

void pt(int x) {
    int d = 2;
    while (d * d <= x) {
        if (x % d == 0) {
            b[d]++;
            x /= d;
        } else {
            d++;
        }
    }
    b[x]++;
}
bool KTNT(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("analyse.inp", "r")) {
        freopen("analyse.inp", "r", stdin);
        freopen("analyse.out", "w", stdout);
    }
}
void Solve() {
    readf();
    for (int i = 0; i < 100001; i++) {
        b[i] = 0;
    }

    for (int i = 0; a[i] != 0; i++) {
        for (int j = 2; j <= a[i]; j++) {
            pt(j);
        }
        for (int j = 2; j <= a[i]; j++) {
            if (KTNT(j) && b[j] != 0) {
                cout << b[j] << " ";
            }
        }
        cout << endl;
        memset(b, 0, sizeof(b));
    }
}
int main() {
    Task();
    Solve();
    return 0;
}