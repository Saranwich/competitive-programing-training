#include <bits/stdc++.h>
using namespace std;

void solve (){
    long long n;
    cin >> n;
    if (n <= 3) {cout << n << "\n"; return;}
    cout << (n&1) <<"\n";

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}