#include <bits/stdc++.h>
using namespace std;

#define task "MCL"
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
const ll MOD = 1e9 + 7;
ll n, d, a[N], c[N], k;
//
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
/*1 2 5 6 9 10 11 15 20*/
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], c[i] = c[i - 1] + a[i];
    ll dem = 0;
    //for (int i = 1; i <= n; i++) cout << c[i] << " "; cout << el;
    int l;
    for (int r = 1; r <= n; r++){
        l = upper_bound(c, c + r, c[r] - k) - c;
        if (l > 0) dem += l;
    }
    cout << dem;
}

int main() {
    tassk();
    solve();
    return 0;
}

/*
n, d, k, a[N];
số lượng số

10 3 3 
2 5 8 4 7 10 11
tìm số tạo ra dãy con tm điều kiện
tìm kiếm tuần tự

sort (merge sort)

chia xâu lớn thành các xâu con đồng chất, tạo ra 
1|22|3|1|44 xâu con = 0 liên tiếp, đoạn con liên tiếp
số đoan con đồng chất

mã hóa xâu --> change back into xâu con đồng chất một cách tốt nhất, biến đổi = cho sẵn
phân đoạn con bằng nhau
*/