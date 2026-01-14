#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int negative = 0;
    int zero = 0;
    int inp;

    for (auto i {0} ; i < n; i++) {
        cin >> inp;
        if (inp == 1) continue;
        if (inp) negative++; else zero++;
    }

    cout << zero + 2 * (negative & 1) << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie();

    int T;
    cin >> T;
    while (T--) solve();
    
}