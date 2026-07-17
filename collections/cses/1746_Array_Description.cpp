// CSES 1746 — Array Description
// https://cses.fi/problemset/task/1746
//
// Array of n numbers, each in 1..m. Some are 0 = UNKNOWN (you choose).
// Rule: neighbours differ by at most 1 (|a[i] - a[i-1]| <= 1).
// Count how many full arrays are possible, mod 1e9+7.
//
// 5-question recipe (fill in words BEFORE coding — 2D: dp[i][v]):
// 1. State      — dp[i][v] =
// 2. Transition —
// 3. Base       —
// 4. Order      —
// 5. Answer     —

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+2,0));
    vector<ll> X(n); for (auto &x : X) cin >> x;

    for (ll i = 1; i <= n; i++){
        ll x = X[i-1];
        if (i == 1){
            if (x == 0) { for (ll v = 1; v <= m; v++) dp[i][v] = 1; }
            else dp[i][x] = 1;
            continue;
        }
        if (x != 0) {
            dp[i][x] = (((dp[i-1][x-1] + dp[i-1][x]) % MOD )+ dp[i-1][x+1]) % MOD;
        }else{
            for (ll j = 1; j <= m; j++){
                dp[i][j] = (((dp[i-1][j-1] + dp[i-1][j]) % MOD )+ dp[i-1][j+1]) % MOD;
            }
        }
    }
    ll ans = 0;
    for(auto i: dp[n]) {
        ans = (ans + i) % MOD;
    }
    cout << ans;
    
}