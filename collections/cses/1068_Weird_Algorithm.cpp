// CSES 1083 — Missing Number
// n ≤ 10 ^ 5, so O(n log n) needed
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n ;
    cin >> n;
    while (n != 1){
        cout << n << " ";
        n = ((n & 1)? (n*3+1): n/2);
    }
    cout << 1;
    
    return 0;
}
