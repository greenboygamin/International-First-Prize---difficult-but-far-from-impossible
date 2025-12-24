#include <bits/stdc++.h>
using namespace std;

#define task ""
#define el "\n"
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

int n, q, par[N], party[N], p[N];
vi adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int finds(int u){
    return par[u] == u ? u : par[u] = finds(par[u]);
}

void unite(int u, int v){
    u = finds(u); v = finds(v);
    if (u != v) par[v] = u;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int p; cin >> p;
        if (p == -1) continue;
        adj[p].pb(i);
        adj[i].pb(p);
        par[i] = i;
    }
    cin >> q;
    while (q--){
        int type, a, b; cin >> type >> a >> b;
        if (type == 1){
            party[a] = b;
            for (int v : adj[a]){
                if (party[v] == b) unite(a, v);
            }
        }
        else {
            a = finds(a); b = finds(b);
            if (a == b) cout << "YES" << el;
            else cout << "NO" << el;
        }
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}

/*
 █████       █████  █████   █████████  █████   ████ █████ █████
▒▒███       ▒▒███  ▒▒███   ███▒▒▒▒▒███▒▒███   ███▒ ▒▒███ ▒▒███ 
 ▒███        ▒███   ▒███  ███     ▒▒▒  ▒███  ███    ▒███  ▒███ 
 ▒███        ▒███   ▒███ ▒███          ▒███████     ▒███  ▒███ 
 ▒███        ▒███   ▒███ ▒███          ▒███▒▒███    ▒███  ▒███ 
 ▒███      █ ▒███   ▒███ ▒▒███     ███ ▒███ ▒▒███   ▒███  ▒███ 
 ███████████ ▒▒████████   ▒▒█████████  █████ ▒▒████ █████ █████
▒▒▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒ 
*//*cho cây n đỉnh đánh số từ 1 tới n, gốc là đỉnh 1. Mỗi đỉnh có trọng số là một số nguyên dương không quá
1e9. Ban đầu mỗi đỉnh nhận một trong 2 màu: đen hoặc trắng.
q thao tác: 
thao tác 1: nhận vào đỉnh 1, đổi màu u, nếu u đang trắng thì đen và ngược lại
thao tác 2: nhận u, xét cây con gốc u, xây dựng một đồ thị vô hướng đầy đủ, có trọng số,
trong đó mỗi đỉnh của đồ thị này tương ứng với một đỉnh màu đen thuộc cây con gốc u.
trọng số của cạnh nối 2 đỉnh trên đồ thị đầy đủ này là khoảng cách giữa 2 đỉnh màu đen tương ứng trên cây. khoảng
cách giữa 2 đỉnh được tính bằng tổng trọng số các cạnh nằm trên đường đi đơn duy nhất giữa hai đỉnh trên cây.
trên đồ thị đầy đủ vừa xây dựng, tiến hành tìm một chu trình có độ dài nhỏ nhất. chu trình xuất phát từ một đỉnh bất kì, 
đi qua tất cả các đỉnh còn lại, mỗi đỉnh qua đúng 1 lần và quay về đỉnh xuất phát. độ dài chu trình được tính bằng
tổng trọng số của các cạnh thuộc tru chình.
thao tác 3: nhận vào 1 đỉnh u, xét cây con gốc u, xây dựng một đò thị vô hướng đầy dủ, có trọng số trương tự như trong
thao tác loại 2. trên đồ thị ddayf đủ vừa xây dựng tiến hành tìm một đường đi có độ dài nhỏ nhất. đường đi xuất phát 
từ 1 đỉnh bất kì, đi qua tất cả các đỉnh con lại, mỗi đỉnh đúng 1 lần. độ dài của đường đi được tính bằng tổng trọng số
của các cạnh thuộc đường đi.

inp: dòng thứ nhất chứa n 
dòng thứ 2 chứa một xâu nhị phân độ dài n trong đó kí tự thứ i là 1 nếu đỉnh ban đầu là màu đen, và ngược lại khi i là 0;
n - 1 dòng tiếp mỗi dòng chứa 3 số nguyên dương u v c mô tả có cạnh nối giữa 2 đỉnh u v trên cây với trọng số c. dữ liệu
đảm bảo n - 1 cạnh tạo thành 1 cây
dòng tiếp theo chứa 1 số nguyên dương q
q dòng tiế[ mỗi dòng dứa 2 số nguyên dương là t và u mô tả thao tác, t = 1 2 3 tương ứng các thao tác trên
*/
