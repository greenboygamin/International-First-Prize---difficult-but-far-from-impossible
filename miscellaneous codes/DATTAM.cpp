#include <bits/stdc++.h>
using namespace std;

#define task "PIZZA"
#define ll long long int
#define ld long double
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue

const ll N = 1e6 + 2;
const ll M = 1e3 + 2;
const ll MOD = 2111992;
const ll INF = 1e9 + 7;

ll n, m, q, c[N], cake[N];
vector<vll> storecomp;
vector<ll> adj[N];
vector<bool> visited(N, 0);
ld result[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<vll> ans;
    ll dem = 0;
    for (int i = 1; i <= n; i++){
        vll tmp;
        tmp.pb(i);
        dem++;
        for (auto j : adj[i]){
            tmp.pb(j);
        }
        ans.pb(tmp);
    }
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << el;
    }
    cout << dem;
}

int main() {
    tassk();
    solve();
    return 0;
}
