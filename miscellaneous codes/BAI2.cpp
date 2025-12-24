#include <bits/stdc++.h>
using namespace std;
#define task "BAI2"
#define ll long long int
#define pb push_back
#define el "\n"
#define vpll vector<pair<ll, ll>> 
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sll stack<ll>
#define qll queue<ll>
#define dqll deque<ll>
#define pq priority_queue
const int N = 2e5 + 5;
const int M = 998244353;
const int modinv2 = (M + 1) / 2;
 
int n, m;
pair<int,int> booth[N];
int last[N];
int ans;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
void compress() {
	set<int> s;
	for (int i = 1; i <= n; i++) s.insert(booth[i].first);
	vector<int> b(s.begin(), s.end());
	for (int i = 1; i <= n; i++) booth[i].second = lower_bound(b.begin(), b.end(), booth[i].first) - b.begin() + 1;
}
 
void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> booth[i].first;
	compress();
}
 
int cnt(int n) {
	return (((1LL * n * (n + 1)) % M) * modinv2) % M;
}
 
void solve() {
	memset(last, 0, sizeof(last));
	ans = 0;
	int sum = cnt(m);
	for (int i = 1; i <= n; i++) {
		if (last[booth[i].second] == 0) sum = (sum + M - booth[i].first) % M;
		int l = last[booth[i].second] + 1, r = i - 1;
		if (l <= r) ans = (ans + ((1LL * cnt(r - l + 1) * booth[i].first) % M)) % M;
		last[booth[i].second] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (last[booth[i].second] != 0) {
			int l = last[booth[i].second] + 1, r = n;
			if (l <= r) ans = (ans + ((1LL * cnt(r - l + 1) * booth[i].first) % M)) % M;
			last[booth[i].second] = 0;
		}
	}
	int tmp = cnt(n);
	sum = (1LL * sum * tmp) % M;
	ans = (ans + sum) % M;
	cout << ans << '\n';
}

int main() {
    tassk();
    Input();
    solve();
    return 0;
}
