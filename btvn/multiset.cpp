#include <bits/stdc++.h>
using namespace std;

#define task "MULTISET"
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
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

unordered_map<int, ll> cnt[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int luckii(int a, int b){
    return (b == 0 ? a : luckii(b, a % b));
}

void solve() {
    string query; int x, y, z, v;
    cin >> query;
    if (query == "SET"){
        cin >> x >> v;
        cnt[x].clear();
        cnt[x][v]++;
    }
    if (query == "SUM"){
        cin >> z >> x >> y;
        unordered_map<int, ll> tmp;
        for (auto i : cnt[x]){
            tmp[i.first] += i.second;
        }
        for (auto i : cnt[y]){
            tmp[i.first] += i.second;
        }
        cnt[z] = tmp;
    }
    if (query == "GCD"){
        cin >> z >> x >> y;
        unordered_map<int, ll> tmp;
        for (auto i : cnt[x]){
            for (auto j : cnt[y]){
                tmp[luckii(i.first, j.first)] += i.second * j.second;
            }
        }
        cnt[z] = tmp;
    }
    if (query == "ASK"){
        cin >> x >> v;
        cout << cnt[x][v] % 2;
    }
}

int main() {
    tassk();
    int n, q; cin >> n >> q;
    while (q--)
    solve();
    return 0;
}