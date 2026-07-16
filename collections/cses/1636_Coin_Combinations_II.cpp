// CSES 1636 — Coin Combinations II
// https://cses.fi/problemset/task/1636
//
// 5-question recipe (fill in words BEFORE coding):
// 1. State      — dp[x] =
// 2. Transition —
// 3. Base       —
// 4. Order      —
// 5. Answer     —
//
// counting DP -> SUM + mod 1e9+7 inside the loop (same recurrence as 1635)
// UNORDERED sets (2+3 == 3+2): FLIP the loops -> coins OUTSIDE, sum INSIDE
// think: why does putting coins outside stop 3+2 from being counted after 2+3?

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, x; cin >> n >> x;
    vector<ll> coins(n); for(auto &c: coins) cin >> c;
    vector<ll> dp(x+1); dp[0] = 1;

    for (auto &c: coins){
        for (ll i = 1; i <= x; i++){
            if (i - c >= 0){
                dp[i] = (dp[i] + dp[i-c]) % MOD;
            }
        }
    }

    cout << dp[x];
}