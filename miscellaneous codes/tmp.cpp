#include <bits/stdc++.h>
using namespace std;

#define task "superconn"
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 405; // Tổng N <= 400
const int INF = 1e9;

int t, n;
int d[MAXN][MAXN];
vector<pii> bad; // Danh sách các cặp đỉnh có khoảng cách > K

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

// Hàm kiểm tra xem có thể đạt được đường kính K không
// Cách làm "trâu": Duyệt u, v và kiểm tra từng cặp xấu
bool check(int K) {
    bad.clear();
    // 1. Lọc các cặp có khoảng cách > K
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i][j] > K) {
                bad.pb({i, j});
            }
        }
    }
    
    // Nếu không có cặp nào > K thì K đã thỏa mãn ngay lập tức
    if (bad.empty()) return true;

    // 2. Sắp xếp giảm dần để tối ưu (Heuristic: check cặp khó nhất trước)
    sort(bad.begin(), bad.end(), [&](const pii &a, const pii &b) {
        return d[a.fi][a.se] > d[b.fi][b.se];
    });

    // 3. Duyệt trâu tất cả các vị trí có thể đặt dây siêu dẫn (u, v)
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) { // Chỉ cần duyệt v > u
            bool ok = true;
            
            // Kiểm tra xem dây (u, v) có cứu được TẤT CẢ các cặp xấu không
            for (auto &p : bad) {
                int i = p.fi;
                int j = p.se;
                
                // Khoảng cách mới khi đi qua dây siêu dẫn (u, v) có trọng số 0
                // Đường đi: i -> u -> v -> j  HOẶC  i -> v -> u -> j
                int new_dist = min(d[i][u] + d[v][j], d[i][v] + d[u][j]);
                
                // Nếu vẫn lớn hơn K thì dây (u, v) này vô dụng -> thử dây khác ngay
                if (new_dist > K) {
                    ok = false;
                    break; 
                }
            }
            
            // Nếu tìm được một dây (u, v) thỏa mãn hết -> K khả thi
            if (ok) return true;
        }
    }
    
    return false;
}

void solve() {
    cin >> n;
    // Khởi tạo ma trận kề từ input
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (i == j) d[i][j] = 0;
            else if (s[j] == '1') d[i][j] = 1;
            else d[i][j] = INF;
        }
    }

    // 1. Floyd-Warshall: Tính khoảng cách gốc O(N^3)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // 2. Binary Search kết quả O(logN * N^4) 
    // Thực tế nhanh hơn nhiều nhờ break sớm
    int l = 0, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << el;
}

int main() {
    tassk(); 
    cin >> t;
    while (t--) 
        solve();
    return 0;
}