#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

int c, n, m;
int a[N];
pii lay[N];
bool sus[N];
int src_id[N];
int type[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> c >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++){
        cin >> lay[i].first >> lay[i].second;
    }
    for (int i = 1; i <= n; i++) sus[i] = (a[i] == 1);
    for (int i = m; i >= 1; i--){
        int u = lay[i].first, v = lay[i].second;
        if (!sus[u] || !sus[v]){
            sus[u] = 0; sus[v] = 0;
        }
    }
    if (c == 1){
        for (int i = 1; i <= n; i++) cout << (sus[i] ? 1 : 0);
    }
    else {
        for (int i = 1; i <= n; i++){
            if (sus[i]){
                src_id[i] = i;
                type[i] = 1;
            }
            else {
                src_id[i] = 0;
                type[i] = 0;
            }
        }
        for (int i = 1; i <= m; i++){
            int u = lay[i].first, v = lay[i].second;
            int typeU = type[u], typeV = type[v];
            int idU = src_id[u], idV = src_id[v];
            if (typeU == 0 && typeV == 0) continue;
            int nType = 0, nId = 0;
            if (typeU == 0){
                nType = typeV;
                nId = idV;
            }
            else if (typeV == 0){
                nType = typeU;
                nId = idU;
            }
            else {
                if (typeU > 1 || typeV > 1 || idU != idV){
                    nType = 2;
                    nId = 0;
                }
                else {
                    nType = 1;
                    nId = idU;
                }
            }
            type[u] = type[v] = nType;
            src_id[u] = src_id[v] = nId;
        }
        for (int i = 1; i <= n; i++){
            if (a[i] == 0) cout << 1;
            else {
                if (!sus[i]) cout << 1;
                else {
                    if (type[i] > 1) cout << 1;
                    else cout << 0;
                }
            }
        }
    }
}


int main() {
    tassk(); 
    solve();
    return 0;
}
 