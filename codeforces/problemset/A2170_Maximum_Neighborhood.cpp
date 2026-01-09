#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n;
    cin >> n;

    if (n == 1) {cout << 1 << "\n"; return;}
    if (n == 2) {cout << 9 << "\n"; return;}
    if (n <= 4) {cout << (4 * (n * n - 1) - n) << "\n"; return;}
    cout << 5 * (n * n - n - 1) << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}