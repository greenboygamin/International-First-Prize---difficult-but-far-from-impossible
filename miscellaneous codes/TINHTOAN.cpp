#include <bits/stdc++.h>
using namespace std;

#define task "TINHTOAN"
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
typedef long double ld;
const ll N = 2e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

string s;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

void solve() {
    cin >> s;
    reverse(s.begin(), s.end());
    stack<int> st;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if ('0' <= (int)c && (int)c <= '9'){
            int tmp = 0, idx = i;
            if ((int)s[i + 1] > '9' || (int)s[i + 1] < '0'){
                while ('0' <= (int)s[idx] && (int)s[idx] <= '9'){
                    tmp = tmp * 10 + ((int)s[idx] - '0');
                    idx--;
                }
            }
            if (tmp || (s[i] == '0' && ((int)s[i + 1] > '9' || (int)s[i + 1] < '0'))) st.push(tmp);
        }
        int a, b;
        if (!s.empty()){
            if (c == 'N' && s[i + 1] == 'I'){
                a = st.top(); st.pop(); b = st.top(); st.pop();
                st.push(min(a, b));
                //cout << a << " " << b << el;
            }
            if (c == 'F' && s[i + 1] == 'I'){
                a = st.top(); st.pop(); b = st.top(); st.pop();
                st.push(a - b);
                //cout << a << " " << b << el;
            }
            if (c == 'M' && s[i + 1] == 'U'){
                a = st.top(); st.pop(); b = st.top(); st.pop();
                st.push(a + b);
                //out << a << " " << b << el;
            }
            if (c == 'D' && s[i + 1] == 'C'){
                a = st.top(); st.pop(); b = st.top(); st.pop();
                st.push(gcd(abs(a), abs(b)));
                //cout << a << " " << b << el;
            }
            if (c == 'X' && s[i + 1] == 'A'){
                a = st.top(); st.pop(); b = st.top(); st.pop();
                st.push(max(a, b));
                //cout << a << " " << b << el;
            }
        }
        
    }
    cout << st.top() << el;
}

int main() {
    tassk(); 
    solve();
    return 0;
}   
