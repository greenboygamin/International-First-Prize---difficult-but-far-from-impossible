#include <bits/stdc++.h>
using namespace std;
#define task "CUTSTR"
#define INF 1e5 + 5
typedef vector<int> vi;
typedef vector<long long> vll;

string pattern, rev_pattern;
vll hash_value, rev_hash, power27;
int n, numQuery;
vector<vi> listSegmentsPerQuery;
set<int> uniqueLengths;
vi listPosition[10005];
vi dp;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init() {
    // Khởi tạo giá trị hash và power
    hash_value.resize(n + 1, 0);
    rev_hash.resize(n + 1, 0);
    power27.resize(n + 1, 1);
    
    for (int i = 1; i <= n; i++) {
        power27[i] = power27[i - 1] * 27;
        hash_value[i] = hash_value[i - 1] * 27 + (pattern[i - 1] - 'a' + 1);
        rev_hash[i] = rev_hash[i - 1] * 27 + (rev_pattern[i - 1] - 'a' + 1);
    }
}

long long getHash(int l, int r, const vll &hash_arr) {
    int len = r - l + 1;
    return hash_arr[r] - hash_arr[l - 1] * power27[len];
}

bool checkPalindrome(int l, int r) {
    long long currentHash = getHash(l, r, hash_value);
    long long reverseHash = getHash(n - r + 1, n - l + 1, rev_hash);
    return (currentHash == reverseHash);
}

void solve() {
    cin >> pattern;
    rev_pattern = pattern;
    reverse(rev_pattern.begin(), rev_pattern.end());
    n = pattern.size();
    init();
    cin >> numQuery;

    // Đọc truy vấn
    for (int query = 0; query < numQuery; query++) {
        int numSegments;
        cin >> numSegments;
        vi listSegments(numSegments);
        for (int i = 0; i < numSegments; i++) {
            cin >> listSegments[i];
            uniqueLengths.insert(listSegments[i]);
        }
        listSegmentsPerQuery.push_back(listSegments);
    }
    
    // Tiền xử lý vị trí palindrome cho từng độ dài đoạn con
    for (set<int>::iterator it = uniqueLengths.begin(); it != uniqueLengths.end(); it++) {
        int len = *it;
        for (int i = 1; i + len - 1 <= n; i++) {
            if (checkPalindrome(i, i + len - 1)) {
                listPosition[len].push_back(i);
            }
        }
    }
    
    // Xử lý từng truy vấn
    for (int query = 0; query < numQuery; query++) {
        vi &listSegments = listSegmentsPerQuery[query];
        int numSegments = listSegments.size();
        
        dp.clear();
        dp.resize(1 << numSegments, INF); // Thay thế thao tác dịch bit bằng tính 2^numSegments
        dp[0] = 0;

        // Thay thế thao tác bitwise bằng if-else
        for (int mask = 0; mask < pow(2, numSegments); mask++) {
            if (dp[mask] == INF) continue;
            for (int i = 0; i < numSegments; i++) {
                // Kiểm tra nếu bit thứ i chưa được chọn
                if (!(mask / int(pow(2, i)) % 2)) { // Kiểm tra bit i đã được set hay chưa
                    int len = listSegments[i];
                    int lo = 0, hi = listPosition[len].size() - 1;
                    int pos = -1;
                    
                    // Binary search để tìm vị trí palindrome
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (listPosition[len][mid] > dp[mask]) {
                            pos = listPosition[len][mid];
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                    
                    if (pos != -1) {
                        // Cập nhật trạng thái mới
                        int newMask = mask + pow(2, i); // Set bit thứ i
                        dp[newMask] = min(dp[newMask], pos + len - 1);
                    }
                }
            }
        }

        // Kiểm tra kết quả cuối cùng
        if (dp[pow(2, numSegments) - 1] <= n) { // Kiểm tra nếu tất cả các segment đã được chọn
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
