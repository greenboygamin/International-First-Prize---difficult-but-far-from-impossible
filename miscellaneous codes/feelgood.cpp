#include <bits/stdc++.h>
using namespace std;
#define task "feelgood"
#define ll long long int
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
ll n, a[N], prf[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }
    ll l = 1, r = 1;
    dqll dqmin;
    
}
int main() {
    tassk();
    solve();
    return 0;
}
/*
void BFS(int s, const std::vector<std::vector<int>>& adjMatrix, std::vector<int>& Tr) {
    int n = adjMatrix.size();
    std::queue<int> Q;
    Q.push(s);
    Tr[s] = s; // Mark the source node as visited

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v = 1; v < n; ++v) {
            if (adjMatrix[u][v] == 1 && Tr[v] == 0) {
                Q.push(v);
                Tr[v] = u; // Mark v as visited and record its predecessor
            }
        }
    }
}*/