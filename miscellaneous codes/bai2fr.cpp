#include <bits/stdc++.h>
using namespace std;
#define task "USB"
struct Fenwick
{
    int n;
    vector<int> bit;
    Fenwick(int _n)
    {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void update(int id, int val)
    {
        for (; id <= n; id += id & -id)
            bit[id] = max(bit[id], val);
    }
    int get_max(int id)
    {
        int res = 0;
        for (; id >= 1; id -= id & -id)
            res = max(res, bit[id]);
        return res;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> c(n + 1);
    vector<long long> all_c;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        all_c.push_back(c[i]);
        all_c.push_back(c[i] + x);
    }
    sort(all_c.begin(), all_c.end());
    all_c.erase(unique(all_c.begin(), all_c.end()), all_c.end());
    auto get_id = [&](long long x)
    {
        return lower_bound(all_c.begin(), all_c.end(), x) - all_c.begin() + 1;
    };
    int m = all_c.size();
    Fenwick dp_0(m);
    Fenwick dp_1(m);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = get_id(c[i]);
        int dp0 = dp_0.get_max(pos - 1) + 1;
        int add_pos = get_id(c[i] + x);
        int dp1 = max(dp_1.get_max(pos - 1) + 1, dp_0.get_max(add_pos - 1) + 1);
        dp_0.update(pos, dp0);
        dp_1.update(pos, dp1);
        ans = max(ans, max(dp0, dp1));
    }
    cout << ans;
    return 0;
}
