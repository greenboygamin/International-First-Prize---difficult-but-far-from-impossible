#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300;
const int INF = INT_MAX;

void Dijkstra(int n, int start, int end, vector<vector<int>>& C) {
    vector<int> d(n + 1, INF); // d[i] là khoảng cách ngắn nhất từ đỉnh start đến đỉnh i
    vector<int> Trace(n + 1, -1); // Trace[i] dùng để lưu vết đường đi
    vector<bool> KT(n + 1, false); // KT[i] kiểm tra xem đỉnh i đã được thăm chưa

    d[start] = 0; // Khoảng cách từ start đến start là 0

    while (true) {
        int u = -1;
        int min = INF;

        // Tìm đỉnh u chưa được thăm có khoảng cách ngắn nhất
        for (int i = 1; i <= n; ++i) {
            if (!KT[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1 || u == end) break; // Nếu không tìm thấy đỉnh hoặc đã đến đỉnh end

        KT[u] = true;

        // Cập nhật khoảng cách cho các đỉnh kề của u
        for (int v = 1; v <= n; ++v) {
            if (!KT[v] && C[u][v] != INF && d[v] > d[u] + C[u][v]) {
                d[v] = d[u] + C[u][v];
                Trace[v] = u;
            }
        }
    }

    // In đường đi từ start đến end và khoảng cách
    if (d[end] == INF) {
        cout << "NO SOLUTION" << endl;
    } else {
        cout << "Khoảng cách ngắn nhất từ " << start << " đến " << end << " là: " << d[end] << endl;
        cout << "Đường đi: ";
        vector<int> path;
        for (int v = end; v != -1; v = Trace[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, start, end;
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;
    cout << "Nhập đỉnh bắt đầu và đỉnh kết thúc: ";
    cin >> start >> end;

    vector<vector<int>> C(n + 1, vector<int>(n + 1, INF));

    cout << "Nhập các cạnh và trọng số (u v h):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, h;
        cin >> u >> v >> h;
        C[u][v] = h;
        C[v][u] = h; // Nếu đồ thị vô hướng, nếu có hướng thì bỏ dòng này
    }

    Dijkstra(n, start, end, C);

    return 0;
}
