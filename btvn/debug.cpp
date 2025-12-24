#include <bits/stdc++.h>
using namespace std;

#define ll long long

const string name = "hamming";

void solve();
signed main()
{
    if (fopen((name + ".inp").c_str(), "r"))
    {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

// main program
const int maxn = 2e6 + 1;

ll GCD(ll a, ll b) { return (b == 0 ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

int len1, len2;
ll total, times, n, m;
int prefix[maxn][26];
string a, b, repeat;
vector<int> trace;

int cnt(int l, int r, char c)
{
    return prefix[r][c - 'a'] - prefix[l - 1][c - 'a'];
}

void solve()
{
    int delta; cin >> delta;
    cin >> n >> m >> a >> b;
    if (a.length() < b.length())
    {
        swap(a, b);
        swap(n, m);
    }
    len1 = a.length();
    len2 = b.length();
    total = LCM(len1, len2);
    times = m / (total / len2);

    if (total == len1)
    {
        int cur = 0;
        string tmp = b;
        while (tmp.length() < len1)
        {
            tmp.push_back(b[cur]);
            cur++;
            if (cur == len2)
                cur = 0;
        }
        ll res = 0;
        for (int i = 0; i < len1; i++)
            res += (a[i] != tmp[i]);
        cout << res * times << '\n';
        return;
    }

    vector<int> used(len1, 0);
    queue<int> q;
    for (int i = 0; i < len1; i++)
        q.push(i);
    ll res = 0;
    while (!q.empty())
    {
        int pos = q.front(); q.pop();
        while (used[pos] == 0)
        {
            repeat.push_back(a[pos]);
            trace.push_back(pos);
            used[pos] = 1;
            pos = (pos + len2) % len1;
        }

        int len = repeat.length();
        for (int i = 0; i < len; i++)
        {
            repeat.push_back(repeat[i]);
            trace.push_back(trace[i]);
        }

        for (int i = 1; i <= 2 * len; i++)
        {
            for (int j = 0; j < 26; j++)
                prefix[i][j] = prefix[i - 1][j];
            prefix[i][repeat[i - 1] - 'a']++;
        }

        for (int i = 0; i < len; i++)
        {
            if (trace[i] >= len2)
                continue;

            char c = b[trace[i]];

            res += m;
            res -= cnt(i + 1, i + len, c) * times;
        }

        while (!q.empty() && used[q.front()] == 1)
            q.pop();
        trace.clear();
        repeat.clear();
    }

    cout << res << '\n';
}
