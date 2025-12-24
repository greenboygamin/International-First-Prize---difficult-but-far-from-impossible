#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int c[N] = {0};
int c1[N] = {0};
int n, m;
void demnt(int n, int a[]) {
    int k = 2;
    while (n != 1) {
        if (n % k == 0) {
            a[k]++;
            n /= k;
        } else {
            k++;
        }
    }
}
int main() {
	/*n!/m!(n-m)! vì n>m nên sẽ rút gọn đc chẳng hạn ntn: 
	(1234567)/(1231234)=(4567)/(1234) vẫn tiếp tục cái ví dụ trên (4567)/(1234)=(2^3537)/(2^33) 
	dễ thấy nếu số mũ của số nguyên tố trên tử lớn hơn dưới mẫu thì đó là ước nguyên tố của S vậy đếm phân phối tử,
	mẫu nếu đếm phân phối trên tử lớn hơn thì kq+1 code:
	*/
	freopen("CPRDIV.INP", "r", stdin); 
    freopen("CPRDIV.OUT", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = m + 1; i <= n; i++) {
        demnt(i, c);
    }
    for (int i = 2; i <= n - m; i++) {
        demnt(i, c1);
    }
    int snt = 0;
    for (int i = 2; i <= N; i++) {
        if (c[i] > c1[i]) {
            snt++;
        }
    }
    cout << snt ;

    return 0;
}