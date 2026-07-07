#include <bits/stdc++.h>
using namespace std;

void solve(){
    int s[4];
    cin >> s[0];
    bool is_valid = true;
    for (int i = 1; i < 4; i++){
        cin >> s[i];
        if (s[i] != s[0]) is_valid = false;
    }

    cout << ((is_valid)? "YES" : "NO") << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}