#include <bits/stdc++.h>
using namespace std;

void solve (){

    int n, alice;
    cin >> n >> alice;

    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];

    int left = 0;
    int right = n;
    int equal = 0;
    for (int i = 0; i < n; i++){
        if (alice < values[i]) break;
        if (alice > values[i]) left += 1;
        else equal += 1;
    }
    right -= (left + equal); 
    int bob;
    if (left > right) bob = alice - 1;else bob = alice+1;
    cout << bob << "\n";

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (auto t{0}; t < T; t++){
        solve();
    }

    return 0;
}