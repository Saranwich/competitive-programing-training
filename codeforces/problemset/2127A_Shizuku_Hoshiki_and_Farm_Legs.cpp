#include <bits/stdc++.h>
using namespace std;

void solved (){
    int n;
    cin >> n;
    cout << ((n & 1)? 0 : (n/4) + 1 ) << "\n";
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t{0}; t < T; t++) solved();

    return 0;
}