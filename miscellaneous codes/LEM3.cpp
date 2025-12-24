#include <bits/stdc++.h>
using namespace std;
#define task "LEM3"
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
const ll INF = 1e9 + 7;
ll n, a[M][M];
bool visited[N];
vector<pll> adj[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            a[i][j] = a[j][i] = x;
        }
    }
    
}   
int main() {
    tassk();
    solve();
    return 0;
}