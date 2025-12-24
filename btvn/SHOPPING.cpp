#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const ll  inf = (ll)1e18 + 1;

#define fi first
#define se second
#define pb push_back

int n;
ll s;
int a[N];

inline void inp() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
}

ll pref[N];

bool getR(int l, int r, ll cost) {
    if (pref[r] - pref[l] - 1ll * (r - l) * a[l] <= cost) return true;
    return false;
}

bool getL(int l, int r, ll cost) {
    if (1ll * (r - l + 1) * a[r] - (pref[r] - pref[l - 1]) <= cost) return true;
    return false;
}
bool check(int len) {
    if (len % 2 == 1) {
        for (int i = len / 2 + 1; i + len / 2 <= n; i++) {
            ll tmps = s;
            if (getR(i, min(n, i + len / 2), tmps)) {
                tmps -= pref[min(n, i + len / 2)] - pref[i] - 1ll * (min(n, i + len / 2) - i) * a[i];
                if (getL(max(1, i - len / 2), i, tmps)) return true;
            }
        }
        return false;
    }
    else {
        for (int i = len / 2; i + len / 2 <= n; i++) {
            ll tmps = s;
            if (getR(i, min(n, i + len / 2), tmps)) {
                tmps -= pref[min(n, i + len / 2)] - pref[i] - 1ll * (min(n, i + len / 2) - i) * a[i];
                if (getL(i - len / 2 + 1, i, tmps)) return true;
            }
        }
        return false;
    }
}

inline void process() {
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    int l = 1, r = n, ans = 0;

    while(l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;
}

int main(void) {
    if (fopen("shopping.inp", "r")) {
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);
    }

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    inp();
    process();

    return 0^0;
}