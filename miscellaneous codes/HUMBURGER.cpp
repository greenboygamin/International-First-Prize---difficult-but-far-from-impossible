#include <bits/stdc++.h>
using namespace std;
#define lli long long int
string s;
const lli inf=1e13, N=1e6+7;
lli nb, ns, nc, pb, ps, pc, r;
lli cb = 0, cs = 0, cc = 0;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(9);
    if (fopen("HUMBERGER.inp", "r")) {
        freopen("HUMBERGER.inp", "r", stdin);
        freopen("HUMBERGER.out", "w", stdout);
    }
}
bool check(lli x){
    lli res = 0;
    res += max(0LL, (cb * x - nb) * pb) + max(0LL, (cs * x - ns) * ps) + max(0LL, (cc * x - nc) * pc);
    return res <= r;
}
void Solve() {
    cin >> s;
    for (char c : s)
    {
        if (c == 'B') cb++;
        else if (c == 'S') cs++;
        else cc ++;
    }
    //cout << cb << " " << cs << " " << cc;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    lli l = 0, r = inf, ans;
    while (l <= r){
        lli mid = (l + r) / 2;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
}
int main() {
    Task();
    Solve();
    return 0;
}