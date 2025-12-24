#include <bits/stdc++.h>
#define ll long long
#define ii int
#define pb push_back
#define pob pop_back
#define ld long double
#define pll pair<long long, long long>
#define pii pair<int,int>
#define vll vector<long long>
#define vii vector<int>
#define X first
#define Y second
#define fileName "FNUMBER"
#define debug(x) cerr << #x << "=" << x << ";\n";
#define el '\n'
#define pq priority_queue
const ll MOD = 1e9 + 7;
const ll MaxLL = 1e18;
const ll N = 1e6  + 5;
using namespace std;
void Start(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(fileName".inp","r")){
        freopen(fileName".inp","r",stdin);
        freopen(fileName".out","w",stdout);
    }
}
void Solve() {
    int n, k;
    string x;
    cin >> n >> k >> x;
    int result = INT_MAX;
    for (char digit = '0'; digit <= '9'; ++digit) {
        vector<int> diffs;
        for (char ai : x) {
            int diff = abs(ai - digit);
            diffs.push_back(diff);
        }
        sort(diffs.begin(), diffs.end());
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += diffs[i];
        }
        result = min(result, sum);
    }

    cout << result;
}

int main()
{
    Start();
    Solve();
}
