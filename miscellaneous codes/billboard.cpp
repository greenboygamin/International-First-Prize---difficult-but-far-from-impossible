#include <bits/stdc++.h>
using namespace std;

#define task "billboard"
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
const ll N = 1e5 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e6;

int r, c;
int board[N], tmp[N], all = 0;

void tassk()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int click(int num){
    return (num ^ (num >> 1) ^ (num << 1)) & all;
}

void solve()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            char x;
            cin >> x;
            if (x == 'X'){
                board[i] |= (1 << j);
            }
        }
    }
    int ans = INT_MAX;
    all = (1 << c) - 1;
    for (int mask = 0; mask < (1 << c); mask++){
        for (int i = 0; i < r; i++) tmp[i] = board[i];
        int res = __builtin_popcount(mask);
        tmp[0] ^= click(mask);
        tmp[1] ^= mask; 
        for (int i = 1; i < r; i++){
            res += __builtin_popcount(tmp[i - 1]);
            tmp[i] ^= click(tmp[i - 1]);
            tmp[i + 1] ^= tmp[i - 1];
        }
        if (tmp[r - 1] == 0) ans = min(ans, res);
    }
    if (ans == INT_MAX) cout << "Damaged billboard.";
    else cout << "You have to tap " << ans << " tiles." << el;
}

int main()
{
    tassk();
    solve();
    return 0;
}