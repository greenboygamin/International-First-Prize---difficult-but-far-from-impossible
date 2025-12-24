#include <bits/stdc++.h>
using namespace std;

#define task "PLAN"
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n, m, parents[N], ans[N], Size[N];
pair<int, int> edges[N];
int order[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void make_set(){
    for (int i = 1; i <= n; i++){
        parents[i] = i;
        Size[i] = 1;
    }
}

int find_set(int u){
    return parents[u] = (parents[u] == u ? u : find_set(parents[u]));
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    if (Size[u] < Size[v]) swap(u, v);
    parents[v] = u;
    Size[u] += Size[v];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> edges[i].first >> edges[i].second;
    }
    for (int i = 1; i <= m; i++){
        cin >> order[i];
    }
    make_set();
    int cnt = n;
    for (int i = m; i >= 1; i--){
        int u = find_set(edges[order[i]].first);
        int v = find_set(edges[order[i]].second);
        if (u == v){
            ans[i] = cnt;
        }
        else {
            ans[i] = cnt--;
            union_set(u, v);
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
