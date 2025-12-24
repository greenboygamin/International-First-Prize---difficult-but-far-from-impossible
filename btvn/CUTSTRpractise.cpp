#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define pb push_back
#define task "CUTSTR"
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 1e6 + 7;
const int M = 1e3 + 7;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f;
string s, revs;
int n, query;
vll hash_value, rev_hash, power27;
vector<vi> SegPerQuery;
set<int> uniqueLength;
vi listPos[N];
vi dp;
void tassk() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) { // Fixed string concatenation
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void init() {
    power27.resize(n + 1, 1);
    hash_value.resize(n + 1, 0);
    rev_hash.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        power27[i] = power27[i - 1] * 27;
        hash_value[i] = hash_value[i - 1] * 27 + (s[i - 1] - 'a' + 1);
        rev_hash[i] = rev_hash[i - 1] * 27 + (revs[i - 1] - 'a' + 1);
    }
}

int get(int l, int r, const vll &curhash) {
    int len = r - l + 1;
    return curhash[r] - curhash[l - 1] * power27[len];
}

bool check(int l, int r) {
    int curs = get(l, r, hash_value);
    int currevs = get(n - r + 1, n - l + 1, rev_hash);
    return (curs == currevs);
}

void solve() {
    cin >> s;
    revs = s;
    n = s.length();
    reverse(revs.begin(), revs.end());
    init();
    cin >> query;
    for (int q = 0; q < query; q++){
        int nums; cin >> nums;
        vi tmpStore(nums);
        for (int i = 0; i < nums; i++){
            cin >> tmpStore[i];
            uniqueLength.insert(tmpStore[i]);
        }
        SegPerQuery.pb(tmpStore);
    }

    for (set<int>::iterator it = uniqueLength.begin(); it != uniqueLength.end(); it++){
        int len = *it;
        for (int i = 1; i + len - 1 <= n; i++){
            if (check(i, i + len - 1)){
                listPos[len].pb(i);
            }
        }
    }
    for (int q = 0; q < query; q++){
        vi &CurQuery = SegPerQuery[q];
        int nums = CurQuery.size();
        dp.clear();
        dp.resize(1 << nums, INF);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << nums); mask++){
            if (dp[mask] == INF) continue;
            for (int i = 0; i < nums; i++){
                if (!(mask & (1 << i))){
                    int len = CurQuery[i];
                    int l = 0, r = listPos[len].size() - 1, pos = -1;
                    while (l <= r){
                        int mid = (l + r) >> 1;
                        if (listPos[len][mid] > dp[mask]){
                            pos = listPos[len][mid];
                            r = mid - 1;
                        }
                        else l = mid + 1;
                    }
                    if (pos != -1){
                        int newMask = mask | (1 << i);
                        dp[newMask] = min(dp[newMask], pos + len - 1);
                    }
                }
            }
        }
        if (dp[(1 << nums) - 1] <= n) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
