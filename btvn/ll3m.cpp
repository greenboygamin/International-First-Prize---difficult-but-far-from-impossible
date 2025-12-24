#include <bits/stdc++.h>
using namespace std;

#define task "ll2m"
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
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
ll n;
struct may{
    ll a, b, idx;
} ct[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
bool cmp(const may &x, const may &y){
    return x.a < y.a;
}

bool ss(const may &x, const may &y){
    return x.b > y.b;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ct[i].a, ct[i].idx = i;
    for (int i = 1; i <= n; i++) cin >> ct[i].b;
    vector<may> ans1, ans2;
    for (int i = 1; i <= n; i++){
        if (ct[i].a <= ct[i].b) {
            ans1.pb(ct[i]);
        }
        else ans2.pb(ct[i]);
    }
    sort(ans1.begin(), ans1.end(), cmp);
    sort(ans2.begin(), ans2.end(), ss);
    /*
    for (may i : ans1) cout << i.a << " " << i.b << el;
    cout << el;
    for (may i : ans2) cout << i.a << " " << i.b << el;*/
    vector<may> ans = ans1;
    for (auto i : ans2) ans.pb(i);
    //for (may i : ans) cout << i.a << " " << i.b << el;
    ll timea = 0, timeb = 0;
    for (int i = 0; i < ans.size(); i++){
        timea += ans[i].a;
        timeb = max(timeb, timea) + ans[i].b;
        //cout << timea << " " << timeb << el;
    }
    cout << timeb << el;
    for (auto i : ans) cout << i.idx << " ";
}

int main() {
    tassk();
    solve();
    return 0;
}
S