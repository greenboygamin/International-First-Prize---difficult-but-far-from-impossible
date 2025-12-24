#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define pip pair<ll,pair<ll,ll>>
#define fi first
#define se second
using namespace std;

const ll mod = 1e9+7;
const ll INF = 1e18;

struct node{
    ll val[2][2];
    int dauL, dauR;
    
    node (){
        memset(val, 0, sizeof val);
        dauL = dauR = 0;
    }
};

int n,q;
ll a[200005];
ll d[200005];
node st[4*200005];

node merge(node &x, node &y){
    if (x.dauR == 0) return y;
    if (y.dauL == 0) return x;
    node z;
    z.dauL = x.dauL;
    z.dauR = y.dauR;
    if (x.dauR == y.dauL){
        for (int i=0;i<=1;i++){
            for (int j=0;j<=1;j++){
                z.val[i][j] = max(z.val[i][j], x.val[i][1] + y.val[1][j]);
            }
        }
        
    }
    for (int i=0;i<=1;i++){
        for (int j=0;j<=1;j++){
            z.val[i][j] = max({z.val[i][j], x.val[i][1] + y.val[0][j], x.val[i][0] + y.val[1][j]});
        }
    }
    return z;
}

void build(int id, int l, int r){
    if (l == r){
        st[id].val[1][1] = abs(d[l]);
        if (d[l] >= 0){
            st[id].dauL = st[id].dauR = 1;
        }
        else st[id].dauL = st[id].dauR = -1;
        return;
    }
    int mid = l+r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = merge(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r){
        st[id].val[1][1] = abs(d[pos]);
        if (d[pos] >= 0){
            st[id].dauL = st[id].dauR = 1;
        }
        else st[id].dauL = st[id].dauR = -1;
        return;
    }
    int mid = l+r >> 1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = merge(st[id*2], st[id*2+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        d[i] = a[i] - a[i-1];
    }
    build(1, 2, n);
    while (q--){
        int l,r,x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r+1] -= x;
        if (l != 1) update(1, 2, n, l, x);
        if (r + 1 <= n) update(1, 2, n, r+1, -x);
        cout << st[1].val[1][1] << '\n';
    }
    return 22^22;
}
