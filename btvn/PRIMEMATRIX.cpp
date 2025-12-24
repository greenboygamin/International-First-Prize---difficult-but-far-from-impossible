#include <bits/stdc++.h>
using namespace std;
#define task "PRIMEMATRIX"
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
ll n, m, a[M][M], f[M][M];
bool isprime[N];
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void sieve(){
    fill(isprime, isprime + N, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= N; i++){
        if (isprime[i]){
            for (int j = i * i; j <= N; j += i){
                isprime[j] = 0;
            }
        }
    }
}
void solve(){
    memset(f, 0, sizeof f);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            ll tmp = a[i][j];
            while (!isprime[tmp]){
                f[i][j]++;
                tmp++;
            }
        }
    }
    ll minx = INF, miny = INF;
    for (int i = 1; i <= n; i++){
        ll sumx = 0;
        for (int j = 1; j <= m; j++){
            sumx += f[i][j];
        }
        minx = min(minx, sumx);
    }
    for (int j = 1; j <= m; j++){
        ll sumy = 0;
        for (int i = 1; i <= n; i++){
            sumy += f[i][j];
        }
        miny = min(miny, sumy);
    }
    ll ans = min(minx, miny);
    cout << ans;
}   
int main() {
    tassk();
    sieve();
    solve();
    return 0;
}