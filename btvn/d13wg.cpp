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
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

string s; int n;
vector<string> words;
ll dist[300][26]; // d[len][last_char];
vi adj[26];

struct state{
    ll d, cur_len, last_char;
    bool operator> (const state &other) const{
        return d > other.d;
    }
};

int find_next(int cur_len, const string &w, bool skip_first){
    int ptr = cur_len;
    int start = (skip_first) ? 1 : 0;
    for (int i = start; i < w.length(); i++){
        if (ptr < s.size() && w[i] == s[ptr]){
            ptr++;
        }
    }
    return ptr;
}
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> s >> n;
    words.resize(n + 1);
    for (int i = 0; i < n; i++){
        cin >> words[i];
        adj[words[i][0] - 'a'].pb(i);
    }
    for (int i = 0; i <= s.size(); i++){
        for (int j = 0; j < 26; j++){
            dist[i][j] = INF;
        }
    }
    priority_queue<state, vector<state>, greater<state>> kiu;
    for (int i = 0; i < n; i++){
        int nm = find_next(0, words[i], false);
        int lc = words[i].back() - 'a';
        ll len = words[i].length();
        if (dist[nm][lc] > len){
            dist[nm][lc] = len;
            kiu.push({len, nm, lc});
        }
    }
    while (!kiu.empty()){
        ll u = kiu.top().cur_len;
        ll c = kiu.top().last_char;
        ll d = kiu.top().d;
        kiu.pop();
        if (d > dist[u][c]) continue;
        if (u == s.size()) continue;
        for (int idx : adj[c]){
            const string &w = words[idx];
            int v = find_next(u, w, true);
            int next_c = w.back() - 'a';
            if (dist[v][next_c] > dist[u][c] + w.length() - 1){
                dist[v][next_c] = dist[u][c] + w.length() - 1;
                kiu.push({dist[v][next_c], v, next_c});
            }
        }
    }
    ll ans = INF;
    for (int j = 0; j < 26; j++) ans = min(ans, dist[s.size()][j]);
    if (ans == INF) cout << -1;
    else cout << ans;
}

int main() {
    tassk(); 
    solve();
    return 0;
}
 