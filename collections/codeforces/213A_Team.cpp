#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n ; cin >> n;
    int a,b,c;
    int counter = 0;
    for (auto i = 0; i < n; i++){
        cin >> a >> b >> c;
        if (a + b + c >= 2) counter++;
    }
    cout << counter ;
    
}  

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    while (T--){
        solve();
    }

    return 0;
}