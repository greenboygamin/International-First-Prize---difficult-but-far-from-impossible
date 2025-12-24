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
const ll N = 1e5 + 5;  
const ll INF = 1e9;

struct node{
    ll sum_d;
    ll max_d;
    ll min_d;
    ll lazy;
    bool full;

    node(){
        sum_d = 0;
        max_d = 0;
        min_d = INF;
        lazy = 0;
        full = false;
    }

    node(ll d){
        sum_d = max_d = min_d = d;
        lazy = 0;
        full = false;
    }
};

int n, q;
int a[N], b[N];
ll pref[N];
int d[N];
node st[4*N];

node merge(node &x, node &y){
    node z;
    z.sum_d = x.sum_d + y.sum_d;
    z.max_d = max(x.max_d, y.max_d);
    z.min_d = min(x.min_d, y.min_d);
    return z;
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = node(d[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = merge(st[id*2], st[id*2+1]);
}

void push(int id, int l, int r){
    if(st[id].full){
        st[id*2].full = st[id*2+1].full = true;
        st[id*2].sum_d = st[id*2+1].sum_d = st[id*2].min_d = st[id*2+1].min_d = st[id*2].max_d = st[id*2+1].max_d = 0;
    } else if(st[id].lazy){
        int mid = (l+r)/2;
        st[id*2].sum_d -= 1LL*st[id].lazy*(mid-l+1);
        st[id*2+1].sum_d -= 1LL*st[id].lazy*(r-mid);
        st[id*2].min_d -= st[id].lazy;
        st[id*2].max_d -= st[id].lazy;
        st[id*2+1].min_d -= st[id].lazy;
        st[id*2+1].max_d -= st[id].lazy;
        st[id*2].lazy += st[id].lazy;
        st[id*2+1].lazy += st[id].lazy;
        st[id].lazy = 0;
    }
}

void update(int id, int l, int r, int u, int v, ll x){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        if(st[id].min_d - x >= 0){
            st[id].sum_d -= 1LL*x*(r-l+1);
            st[id].lazy += x;
            st[id].min_d -= x;
            st[id].max_d -= x;
            return;
        } else if(st[id].max_d - x <= 0){
            st[id].sum_d = st[id].min_d = st[id].max_d = 0;
            st[id].full = true;
            return;
        }
        if(l == r) return;
    }
    push(id, l, r);
    int mid = (l+r)/2;
    update(id*2, l, mid, u, v, x);
    update(id*2+1, mid+1, r, u, v, x);
    st[id] = merge(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return st[id].sum_d;
    push(id, l, r);
    int mid = (l+r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        d[i] = b[i]-a[i];
        pref[i] = pref[i-1] + b[i];
    }
    build(1, 1, n);
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 0){
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l-1] - get(1, 1, n, l, r) << el;
        }
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
