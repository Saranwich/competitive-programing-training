// CSES 1083 — Missing Number  https://cses.fi/problemset/task/1083
// n ≤ 2 * 10 ^ 5, so O(n log n) needed   <-- fill this in BEFORE you code (Lesson 1 habit)
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,b,c ; cin >> n;
    c = (n * (n+1)) / 2;
    vector<int> a; 
    for (auto i = 0; i < n-1 ; i++) {
        cin >> b;
        a.push_back(b);
    }
    c -= accumulate(a.begin(), a.end(), 0LL);
    cout << c;

    return 0;
}

//O(n)
