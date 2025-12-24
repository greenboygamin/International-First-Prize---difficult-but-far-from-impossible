#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll, ll>
#define vpll vector<pll>
#define task "tuoinuoc"
const ll INF = 1e9 + 7;
const int MAX_N = 302; // N <= 300
ll n, w[MAX_N], p[MAX_N][MAX_N];
bool visited[MAX_N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
ll prim() {
    priority_queue<pll, vpll, greater<pll>> pq;
    vector<ll> mins(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        pq.push({w[i], i});
        mins[i] = w[i];
    }
    ll total = 0;
    while (!pq.empty()){
        ll cost = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total += cost;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && p[u][v] < mins[v]) {
                mins[v] = p[u][v];
                pq.push({mins[v], v});
            }
        }
    }
    return total;
}

int main() {
    tassk();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
        }
    }
    cout << prim() << "\n";
    return 0;
}
