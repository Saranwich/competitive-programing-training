// CSES 1633 — Dice Combinations
// https://cses.fi/problemset/task/1633
// n <= 1e6 : n log n needed
// 5-question recipe (fill in words BEFORE coding):
// 1. State      — dp[x] = the numver of ways to construct sum n by throwing the dice
// 2. Transition — dp[x-c] + 
// 3. Base       — dp[0] = 0
// 4. Order      — n - > 0 -> n;
// 5. Answer     — dp[n]

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> dp(n+1,0); dp[0] = 1;

    for (auto i = 0; i <= n; i++){
        for (auto j = 1; j <= 6; j++){
            if (i - j >= 0){
                dp[i] = (dp[i] + dp[i-j]) % ll(1e9+7);
            }
        }
    }
    
    cout << dp[n];
    return 0;
}
