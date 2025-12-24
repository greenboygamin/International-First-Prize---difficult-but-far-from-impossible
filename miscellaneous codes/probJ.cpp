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
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void tassk()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

ll ext_gcd(ll A, ll B, ll &x, ll &y)
{
    if (B == 0)
    {
        x = (A >= 0 ? 1 : -1);
        y = 0;
        return llabs(A);
    }
    ll x1, y1;
    ll g = ext_gcd(B, A % B, x1, y1);
    x = y1;
    y = x1 - (A / B) * y1;
    return g;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    ll res = 0;
    for (int a = 1; a <= n; ++a)
    {
        if (a == x)
            continue;
        for (int c = 1; c < a; ++c)
        {
            ll g = gcd(a, c);
            if (n % g != 0)
                continue;
            ll a1 = a / g, c1 = c / g, n1 = n / g;
            ll inv, tmp;
            ext_gcd(c1, a1, inv, tmp);
            inv %= a1;
            if (inv < 0)
                inv += a1;
            ll d0 = ((a1 - (n1 % a1)) * inv) % a1;
            if (d0 < 0)
                d0 += a1;
            ll b0 = ((ll)n + (ll)c * d0) / a;
            ll t_min = ((1 - d0) + a1 - 1) / a1;
            ll num = (b0 - d0) - 1;
            ll den = (a1 - c1);
            if (den <= 0)
                continue;
            ll t_max = num < 0 ? -1 : (num / den);
            if (t_max < t_min)
                continue;
            ll cnt = t_max - t_min + 1;
            if (x != 0)
            {
                ll numTx = x - b0;
                if (c1 != 0 && numTx % c1 == 0)
                {
                    ll tx = numTx / c1;
                    if (tx >= t_min && tx <= t_max)
                        --cnt;
                }
            }
            if (cnt > 0)
                res += cnt;
        }
    }

    cout << res << el;
}

int main()
{
    tassk();
    solve();
    return 0;
}
