#include <bits/stdc++.h>
using namespace std;

#define task "HAMMING"
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
const ll N = 2e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

ll delta, lena, lenb;
ll n, m, d;
string a, b, cha;
vector<int> idx;
int pref[N][26];

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

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

// dk: ai == bj && i % d == j % d

ll cnt(ll l, ll r, char c)
{
    return pref[r][c - 'a'] - pref[l - 1][c - 'a'];
}

void solve()
{
    cin >> delta >> m >> n >> a >> b;
    if (a.length() < b.length())
        swap(a, b), swap(m, n);
    lena = a.length(), lenb = b.length();
    ll res = 0;
    ll total = lcm(lena, lenb);
    ll times = n / (total / lenb);
    // cout << m << " " << n << " " << total;
    if (total == lena)
    {
        ll tmp = lena / lenb;
        string bb = "";
        for (int i = 1; i <= tmp; i++)
            bb += b;
        for (int i = 0; i < lena; i++)
        {
            res += (a[i] != bb[i]);
        }
        cout << res * times;
        return;
    }
    queue<int> q;
    
    vector<int> check(lena, 0);
    for (int i = 0; i < lena; i++)
        q.push(i);
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        while (!check[pos])
        {
            check[pos] = 1;
            idx.pb(pos);
            cha.pb(a[pos]);
            pos = (pos + lenb) % lena;
        }
        int len = cha.size();
        for (int i = 0; i < len; i++)
        {
            cha.pb(cha[i]);
            idx.pb(idx[i]);
        }
        // for (auto i : cha) cout << i;
        for (int i = 1; i <= len * 2; i++)
        {
            for (int j = 0; j < 26; j++)
                pref[i][j] = pref[i - 1][j];
            pref[i][cha[i - 1] - 'a']++;
        }
        for (int i = 0; i < len; i++)
        {
            if (idx[i] >= lenb)
                continue;
            char c = b[idx[i]];
            res += n;
            res -= cnt(i + 1, i + len, c) * times;
        }
        while (!q.empty() && check[q.front()] == 1)
            q.pop();
        idx.clear();
        cha.clear();
        // cout << el << sim << el;
    }
    cout << res;
}

int main()
{
    tassk();
    solve();
    return 0;
}