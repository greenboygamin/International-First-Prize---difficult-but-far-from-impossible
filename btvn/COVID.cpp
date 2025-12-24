#include <bits/stdc++.h>
using namespace std;

int calc(int g){
    int b = 0;
    while (g){
        b ^= g;
        g >>= 1;
    }
    return b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    vector<int> kits[10];
    for (int i = 1; i <= 1000; i++){
        int g = i ^ (i >> 1); 
        for (int bit = 0; bit < 10; bit++)
            if ((g >> bit) & 1) kits[bit].push_back(i);
    }

    while (T--) {
        for (int bit = 0; bit < 10; bit++){
            int k = (int)kits[bit].size();
            cout << k << ' ';
            for (int i = 0; i < k; i++) cout << kits[bit][i] << ' ';
            cout << '\n';
        }
        cout.flush();

        string res; cin >> res;

        int g = 0;
        for (int i = 0; i < 10; i++){
            if (res[i] == '+') g |= (1 << i);
        }

        if (g == 0){
            cout << 0 << '\n';
            cout.flush();
            continue;
        }

        int i = calc(g);
        if (i < 1 || i > 1000) cout << 0 << '\n';
        else cout << i << '\n';
        cout.flush();
    }
    return 0;
}