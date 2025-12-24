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
const ll N = 1e6 + 5;
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e8;

string ask = "(n*1000000+m*1000+k)";

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    int p = 1, n = 0;
    vector<string> tests;
    for (int i = 0; i < 15; i++)
    {
        cout << "edit " << "(" << ask << "/" << p << ")%4" << el;
        string res; cin >> res;
        tests.pb(res);
        n = (int)res.length();
        p *= 4;
    }

    cout << "answer" << el;
    string str = "WMRT";
    for (int i = 0; i < n; i++)
    {
        int num = 0, p = 1;
        for (int j = 0; j < 15; j++)
        {
            char c = tests[j][i];
            int x = str.find(c);
            num += x * p;
            p *= 4;
        }
        int k = (num % 1000);
        num -= k;
        num /= 1000;
        int m = (num % 1000);
        num -= m;
        int n_val = (num / 1000);
        cout << n_val << ' ' << m << ' ' << k << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}