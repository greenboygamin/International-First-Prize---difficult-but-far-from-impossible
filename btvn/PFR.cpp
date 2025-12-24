#include <bits/stdc++.h>
using namespace std;
#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
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
const ll N = 1e5 + 5;
const ll M = 2e3 + 5;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

int n;
int p[N];
int to[N], pos[N];
vector<vector<int>> rev;
vector<int> dist;
vector<int> vis2;
vector<int> primes;
unordered_map<int,int> maxPow;

ll exp(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<int> path, cyc;
    
    for(int i=1;i<=n;i++){
        if(to[i] != 0) continue;
        path.clear();
        int v = i;
        while(to[v] == 0){
            to[v] = 1;
            pos[v] = (int)path.size();
            path.push_back(v);
            v = p[v];
        }
        if(to[v] == 1){
            int start = pos[v];
            int clen = (int)path.size() - start;
            cyc.push_back(clen);
        }
        for(int node : path){
            to[node] = 2;
            pos[node] = -1;
        }
    }
    
    rev.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) rev[p[i]].pb(i);
    
    queue<int> q;
    dist.assign(n + 1, -1);
    vis2.assign(n + 1, 0);
    for(int i=1;i<=n;i++){
        if(vis2[i]) continue;
        int v = i;
        vector<int> st;
        while(!vis2[v]){
            vis2[v] = i; 
            st.pb(v);
            v = p[v];
        }
        if(vis2[v] == i){
            int u = v;
            do{
                dist[u] = 0;
                q.push(u);
                u = p[u];
            } while(u != v);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int nei : rev[u]){
            if(dist[nei] == -1){
                dist[nei] = dist[u] + 1;
                q.push(nei);
            }
        }
    }
    
    ll T = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] > T) T = dist[i];
    }

    int lim = (int)sqrt(n) + 2;
    vector<char> check(lim + 1, 0);
    for(int i = 2;i <= lim;i++){
        if(!check[i]){
            primes.push_back(i);
            if(1ll * i * i <= lim)
                for(int j =  i* i; j <= lim; j += i) check[j] = 1;
        }
    }
    
    maxPow.reserve(64);
    for(int len : cyc){
        int x = len;
        for(int pr : primes){
            if(1ll * pr * pr > x) break;
            if(x % pr == 0){
                int cnt = 0;
                while(x % pr == 0){
                    x /= pr; 
                    cnt++;
                }
                auto it = maxPow.find(pr);
                if(it == maxPow.end() || it->se < cnt) maxPow[pr] = cnt;
            }
        }
        if(x > 1){
            auto it = maxPow.find(x);
            if(it == maxPow.end() || it->se < 1) maxPow[x] = 1;
        }
    }
    
    ll L = 1;
    for(auto &pe : maxPow){
        int prime = pe.fi;
        int e = pe.se;
        L = (L * exp(prime, e)) % MOD;
    }

    ll ans = ( (T % MOD) + L ) % MOD;
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}