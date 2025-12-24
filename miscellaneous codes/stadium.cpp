#include <bits/stdc++.h>
using namespace std;
#define task "stadium"
#define ll long long
#define pb push_back
long long m, n, x, ans = 0;
const ll N = 1e6 + 2;
vector<ll> freq(N);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        cin >> x;
        freq[x]++;
    }
    for (int i = N - 1; i >= 0; i--){
        ans += min(freq[i], n) * i;
        n -= min(freq[i], n);
        if (n == 0) break;
        freq[i - 1] += freq[i];
    }
    cout << ans;
    return 0;
}
