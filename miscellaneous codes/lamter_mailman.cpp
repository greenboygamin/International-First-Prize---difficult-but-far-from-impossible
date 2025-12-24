#include <bits/stdc++.h>
using namespace std;

#define task ""
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

const ll N = 55; 
const ll INF_LL = 4e18; 
const int INF_INT = 2e9;

int n;
char a[N][N];
int h[N][N];
int pr, pc; 
vector<pii> k_locs;
int k_total = 0;
bool visited[N][N];

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

bool check(int min_h, int max_h) {
    if (h[pr][pc] < min_h || h[pr][pc] > max_h) {
        return false;
    }
    for (const auto& loc : k_locs) {
        if (h[loc.first][loc.second] < min_h || h[loc.first][loc.second] > max_h) {
            return false;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }

    queue<pii> q;
    q.push({pr, pc});
    visited[pr][pc] = true;
    int k_found = 0;

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;

        if (a[r][c] == 'K') {
            k_found++;
        }

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (is_valid(nr, nc) && !visited[nr][nc]) {
                if (h[nr][nc] >= min_h && h[nr][nc] <= max_h) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    return k_found == k_total;
}


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    set<int> nen;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'P') {
                pr = i;
                pc = j;
            } else if (a[i][j] == 'K') {
                k_locs.pb({i, j});
                k_total++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
            nen.insert(h[i][j]);
        }
    }

    vector<int> vh(nen.begin(), nen.end());
    int k = vh.size();
    int ans = INF_INT;

    int i = 0, j = 0;
    
    while (i < k) {
        bool ok = false;
        while (j < k) {
            if (check(vh[i], vh[j])) {
                ans = min(ans, vh[j] - vh[i]);
                ok = true;
                break; 
            } else {
                j++;
            }
        }
        
        if (!ok) {
            break; 
        }
        
        i++;
    }
    
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}