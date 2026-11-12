#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve(){
    ll a,b,c; cin >> a >> b >> c;
    if (a == c || b == c || a ==c){
        cout << "NO\n"; return;
    } 

    if ((b == (a + (c-b))) && (c-b == 1)){
        cout << "YES\n"; return;
    }

    cout << "NO\n";
}

int main (){
    int T; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}