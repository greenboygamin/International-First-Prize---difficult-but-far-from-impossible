#include "dpair.h"
#include <bits/stdc++.h>
using namespace std;

#define task "d13jobshop"
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
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = INT_MAX;
const ll MOD = 998244353;

int n;

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void Solve() {
    cin >> n; 
    string mask(n + 1, '0');
    for (int i = 0; i <= n; i++) {
        mask[i] = '1';
        if (mcheckdup(mask)) {
            int first = -1, second = -1;
            for (int j = 0; j <= n; j++) {
                if (mask[j] == '1') {
                    if (first == -1) first = j;
                    else { second = j; break; }
                }
            }
            mtell(first, second);
            return;
        }
        mask[i] = '0';
    }
    for (int i = 0; i <= n; i++) {
        msetd(1); 
        if (mcheck(i)) {
            mseti(i); 
            for (int j = 0; j <= n; j++) {
                if (i == j) continue;
                if (mcheck(j)) {
                    mtell(i, j);
                    return;
                }
            }
        }
    }
}

int main() {
    Task();
    Solve();
    return 0;
}
