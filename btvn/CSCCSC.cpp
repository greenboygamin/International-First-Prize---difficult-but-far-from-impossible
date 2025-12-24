#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
typedef long long int ll;
const ll N = 1e6 + 5;

ll n, d, k;
ll a[N];
unordered_set<ll> s;
/*bool chimto(ll l, ll r, ll x){
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (a[mid] == x){
            return true;
        }
        else if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}*/
void solve() {
    cin >> n >> d >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    ll dem = 0;
    for (int i = 1; i <= n; i++){
        ll start = a[i];
        bool tmp = 1;
        for (int i = 1; i < k; i++){
            start += d;
            //cout << start << " ";
            if (s.find(start) == s.end()){
                tmp = 0;
                break;
            }
        }
        if (tmp) dem++;
    }
    cout << el << dem;
}
void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
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