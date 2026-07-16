// CSES 1637 — Removing Digits
// https://cses.fi/problemset/task/1637
//
// 5-question recipe (fill in words BEFORE coding — เขียนก่อนโค้ดนะ):
// 1. State      — dp[x] = optimal step to subtract x to 0
// 2. Transition — dp[x-c] + 1
// 3. Base       — dp[0] = 0
// 4. Order      — 0 -> n
// 5. Answer     — dp[x]
//
// optimisation DP -> MIN steps to reach 0 (like Minimizing Coins, dp[0]=0)
// twist: the "moves" are the DIGITS of x itself (subtract one digit of x each step)
// e.g. x=27 -> digits {2,7} -> can go to 25 or 20
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> get_choices(ll n){
    set<ll> s;
    ll cn = n;
    while (cn > 0) {
        s.insert(cn % 10);
        cn /= 10;
    }
    return s;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ; cin >> n;
    vector<ll> dp(n+1, 1e9); dp[0] = 0;
    
    for (ll i = 1 ; i <= n; i++){
        set<ll> s = get_choices(i);
        for (auto c: s){
            if (i - c >= 0 && dp[i-c] != 1e9 && dp[i-c] + 1 < dp[i]) {
                dp[i] = dp[i-c] + 1;
            }
        }
    }

    cout << ((dp[n] != 1e9)? dp[n]: -1);

}