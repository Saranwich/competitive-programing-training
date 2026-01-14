#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int last_met = -1 * k;
    int counter = 0;

    for (auto i{0}; i < n; i++){
        if (s[i] == '0') continue;
        if (i - last_met >= k) {
            counter++;
        }
        last_met = i;
    }

    cout << counter << "\n";
}   

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}