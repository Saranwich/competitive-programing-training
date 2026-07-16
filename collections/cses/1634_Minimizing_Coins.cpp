// CSES 1634 — Minimizing Coins
// https://cses.fi/problemset/task/1634
// n : 
// 5-question recipe (fill in words BEFORE coding — get this right this time):
// 1. State      — dp[x] = optimal solution sum of money x
// 2. Transition — dp[x-i] + 1
// 3. Base       — dp[0] = 0 -> 0 coin for 0 money
// 4. Order      — 0 -> n
// 5. Answer     — dp[x]
//
// remember: MIN shape -> INF sentinel, guard dp[x-c] != INF, print -1 if unreachable

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll INF = 1e9;
    ll n, x; cin >> n >> x;
    vector<ll> coin(n); for (auto &c: coin) cin >> c; 
    vector<ll> dp(x+1,INF); dp[0] = 0;

    for (auto i = 1; i <= x; i++){
        for (auto c : coin){
            if (i - c >= 0 && dp[i-c]!= INF){
                if (dp[i-c] + 1 < dp[i])
                dp[i] = dp[i-c] + 1;
            }
        }
    }
    cout << ((dp[x] != INF)? dp[x]:-1);    
}