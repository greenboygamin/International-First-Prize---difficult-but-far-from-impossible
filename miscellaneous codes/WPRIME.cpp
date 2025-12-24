#include <bits/stdc++.h>
using namespace std;

#define task "EMPLOYEE"
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
const ll MOD = 1e6;

int n, num_child[N];
bool visited[N];
vector<int> adj[N], rev[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        for (int x = 1; x <= k; x++){
            int j; cin >> j;
            adj[j].pb(i); 
        }
    }
    queue<int> q;
    long long ans = INF;
    for (int boss = 1; boss <= n; boss++)
    {
        long long sum = 0;
        int cnt = 0;
        vector<int> dist(n + 1, -1);
        dist[boss] = 1;
        q.push(boss);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            sum += dist[u];
            cnt++;
            for (auto v : adj[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        if (cnt == n) ans = min(ans, sum);
    }
    cout << ans;
}

int main() {
    Task();
    Solve();
    return 0;
}


