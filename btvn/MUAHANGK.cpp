#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> kiull;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

ll n, k;
pll a[200005];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> kiu;
    ll cnt = 1;
    kiu.push({a[1].first, {1, 1}});
    ll ans = 0;
    while (!kiu.empty() && cnt < k)
    {
        pair<ll, pll> top = kiu.top();
        kiu.pop();
        ll cost = top.first;
        ll i = top.second.first;
        ll b = top.second.second;
        cnt++;
        ans = cost;
        if (b < a[i].second)
        {
            kiu.push({cost + a[i].first, {i, b + 1}});
        }
        if (i != n)
        {
            if (b == 1)
                kiu.push({cost + a[i + 1].first - a[i].first, {i + 1, 1}});
            kiu.push({cost + a[i + 1].first, {i + 1, 1}});
        }
    }
    cout << ans;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 