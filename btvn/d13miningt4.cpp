#include <bits/stdc++.h>
using namespace std;

#define task "d13jobshop"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = INT_MAX;
const ll MOD = 998244353;

int n, m, q;
int a[M][M];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
bool visited[M][M];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

struct SegmentTree {
    int size;
    vector<pii> st; 

    pii combine(pii a, pii b) {
        if (a.first != b.first) 
            return (a.first > b.first ? a : b);
        return (a.second < b.second ? a : b);
    }

    void init(int n) {
        size = n;
        st.assign(4 * n, {0, INT_MAX});
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = {a[1][l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        st[id] = combine(st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            st[id] = {val, l}; 
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        st[id] = combine(st[id * 2], st[id * 2 + 1]);
    }

    pii get(int id, int l, int r, int u, int v) {
        if (u > r || v < l) return {0, INT_MAX}; 
        if (u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
} Tree;


bool check(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != -1);
}

void bfs(int x, int y){
    memset(visited, 0, sizeof visited);
    int maxs = (a[x][y] == -1) ? -1e9 : a[x][y];
    vector<pii> sto;
    queue<pii> q;
    q.push({x, y});
    while (!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        if (visited[cx][cy]) continue;
        visited[cx][cy] = 1;
        for (int k = 0; k < 4; k++){
            int nx = cx + px[k];
            int ny = cy + py[k];
            if (check(nx, ny)){
                maxs = max(maxs, a[nx][ny]);
                q.push({nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (visited[i][j] && a[i][j] == maxs){
                a[i][j] = 0;
                cout << maxs << el;
                return;
            }
        }
    }
}

void sub3(){
    Tree.init(m);
    Tree.build(1, 1, m);
    for (int i = 1; i <= q; i++){
        int type, x, y; cin >> type >> x >> y;
        if (type == 1){
            // bien trai phai
            int l = 1, r = y, left = 0, right = m + 1;
            while (l <= r){
                int mid = (l + r) / 2;
                if (a[x][mid] == -1){
                    l = mid + 1;
                    left = mid;
                }
                else r = mid - 1;
            }
            l = y, r = m;
            while (l <= r){
                int mid = (l + r) / 2;
                if (a[x][mid] == -1){
                    r = mid - 1;
                    right = mid;
                }
                else l = mid + 1;
            }
            //cout << left << " " << right << el;
            int L = left + 1;
            int R = right - 1;
            if (L <= R) {
                auto [val, pos] = Tree.get(1, 1, m, L, R);
                cout << val << "\n";
                Tree.update(1, 1, m, pos, 0);
            }
        }
        else if (type == 2){
            Tree.update(1, 1, m, y, -1);
            a[x][y] = -1;
        }
    }
}

void sub12(){
    for (int i = 1; i <= q; i++){
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) bfs(x, y);
        if (type == 2) a[x][y] = -1;
    }
}

void Solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    if (n <= 100 && m <= 100 && q <= 100) sub12();   
    else sub3();
}

int main() {
    Task();
    Solve();
    return 0;
}
