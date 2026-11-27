#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve (){

    ll x; cin >> x;

    if ( x % 2 == 0 && x % 4 != 0) {
        cout << "NO\n"; return;
    }

    cout << "YES\n";
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T; cin >> T; while (T--) solve();
    return 0;
}