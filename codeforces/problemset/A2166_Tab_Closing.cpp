#include <bits/stdc++.h>
using namespace std;

void solve (){
    long long a,b,c;
    cin >> a >> b >> c;

    cout << ((b >= a || (b * c <= a))? 1:2) << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
}