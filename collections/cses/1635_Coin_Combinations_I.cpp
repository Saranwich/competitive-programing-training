// CSES 1635 — Coin Combinations I
// https://cses.fi/problemset/task/1635
//
// 5-question recipe (fill in words BEFORE coding):
// 1. State      — dp[x] =
// 2. Transition —
// 3. Base       —
// 4. Order      —
// 5. Answer     —
//
// counting DP -> SUM + mod 1e9+7 inside the loop (like Dice)
// ORDERED (2+3 != 3+2): loop  sum OUTSIDE, coins INSIDE

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x; cin >> n >> x;
    vector<ll> coins(n); for (auto &c: coins) cin >> c;
    vector<ll> dp(x+1); dp[0] = 1;

    for (ll i = 1; i <= x; i++){
        for (auto c: coins){
            if (i-c >= 0){
                dp[i] = (dp[i] + dp[i-c]) % MOD;
            }
        }
    }

    cout << dp[x];

}