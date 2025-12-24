#include <bits/stdc++.h>
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
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

int n, k;
int a[1000005];
ll pref[1000005];
int st[20][1000005];
int LOG[1000005];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int get(int l, int r)
{
    int k = LOG[r - l + 1];
    return __gcd(st[k][l], st[k][r - (1 << k) + 1]);
}


void solve() {
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        st[0][i] = a[i];
    }
    LOG[0] = LOG[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        LOG[i] = LOG[i / 2] + 1;
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        int g = a[i];
        while (j <= n)
        {
            int l = j, r = n;
            int pos = n + 1;
            while (l <= r)
            {
                int mid = l + r >> 1;
                if (get(i, mid) != g)
                {
                    r = mid - 1;
                    pos = mid;
                }
                else
                    l = mid + 1;
            }
            if (pos - i >= k)
                ans = max(ans, 1LL * g * (pref[pos - 1] - pref[i - 1]));
            g = get(i, pos);
            j = pos;
        }
    }
    cout << ans;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 