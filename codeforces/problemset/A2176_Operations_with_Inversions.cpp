#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n;
    cin >> n;

    long long prev; cin >> prev;
    int counter = 0;
    long long temp;
    for (auto i{0}; i < n-1; i++){
        cin >> temp;
        if (temp < prev) {
            counter++;
            continue;
        }

        prev = temp;
    }

    cout << counter << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t = 0; t < T; t++) solve();

    return 0;
}