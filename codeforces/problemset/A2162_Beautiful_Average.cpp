#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n; cin >> n;
    int highest = -1;
    int temp;

    for (auto i{0}; i < n; i++){
        cin >> temp;
        highest = max(highest,temp);
    }

    cout << highest << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
}