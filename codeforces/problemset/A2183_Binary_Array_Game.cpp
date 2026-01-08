#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> vals (n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    if (vals[0] || vals[n-1]) cout << "ALICE\n";
    else cout << "BOB\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t = 0; t < T; t++)solve();
}