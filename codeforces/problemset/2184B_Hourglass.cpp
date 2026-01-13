#include <bits/stdc++.h>
using namespace std;

void solve (){
    long long s,k,m;
    cin >> s >> k >> m;
    if (k >= s) {
        cout << max((long long)0, s - (m%k)) << "\n"; return;
    }

    m%= k*2;
    if (m < k) {
        cout << max((long long)0, s-m);
    }else{
        cout << max((long long)0, k-(m-k));
    }

    cout << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}