#include <bits/stdc++.h>
using namespace std;

#define task "delta"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 5e3 + 7;
const ll B = 1e6;
const ll INF = 1e18;
const ll MOD = 998244353;

ll theta, n, k;
struct data{
    ll val, id;
} a[N];
ll cnt[N];
set<ll> vals;

ll pow2[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

ll add(ll a, ll b){
    return (a + b) % MOD;

}

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll calc(ll n){
    return (n * (n + 1)) / 2;
}

ll modpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}       

void init(){
    pow2[0] = 1;
    for (int i = 1; i < N; i++) pow2[i] = mul(pow2[i - 1], 2);
}

void compress(){
    vector<ll> v(vals.begin(), vals.end());
    for (int i = 1; i <= n; i++){
        a[i].id = lower_bound(v.begin(), v.end(), a[i].val) - v.begin() + 1;
    }
}

void Solve(){
    cin >> theta >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].val;
        vals.insert(a[i].val);
    }
    init();
    ll ans1 = 0, ans2 = 0;
    deque<int> dqMin, dqMax;
    int l = 1;
    for (int r = 1; r <= n; r++){    
        while (!dqMin.empty() && a[dqMin.back()].val >= a[r].val) dqMin.pop_back();
        dqMin.pb(r);
        while (!dqMax.empty() && a[dqMax.back()].val <= a[r].val) dqMax.pop_back();
        dqMax.pb(r);
        while (!dqMin.empty() && !dqMax.empty() && a[dqMax.front()].val - a[dqMin.front()].val > k){
            if (dqMin.front() == l) dqMin.pop_front();
            if (dqMax.front() == l) dqMax.pop_front();
            ++l;
        }
        ans1 = add(ans1, (r - l + 1));
    }
    cout << ans1 << " ";
    compress();
    for (int i = 1; i <= n; i++) cnt[a[i].id]++;
    vector<ll> vals2;
    vector<int> cts;
    for (int v : vals){
        vals2.pb(v);
        cts.pb(cnt[vals2.size()]);
    }
    int s = vals2.size();
    vector<int> pref(s + 1, 0);
    for (int i = 1; i <= s; i++) pref[i] = pref[i - 1] + cts[i - 1];
    int j = 0;
    for (int i = 1; i <= s; i++){
        if (j < i) j = i;
        while (j + 1 <= s && vals2[j] - vals2[i - 1] <= k) ++j;
        int sumRight = pref[j] - pref[i];
        ll left = (pow2[cts[i - 1]] - 1 + MOD) % MOD;
        ll ways = mul(left, pow2[sumRight]);
        ans2 = add(ans2, ways);
    }
    cout << ans2 << el;
}

int main() {
    Task();
    Solve();
    return 0;
}
