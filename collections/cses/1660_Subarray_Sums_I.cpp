// CSES 1660 — Subarray Sums I  https://cses.fi/problemset/task/1660
// n <= 2e5, POSITIVE values. Count subarrays with sum == x.
// approach: prefix sum , O(n log n)   (fill BEFORE coding — positive => sliding window works)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x; cin >> n >> x;
    vector<ll> arr(n);
    vector<ll> pre(n+1); pre[0]=0;
    for (auto i = 0; i < n; i++){
        cin >> arr[i];
        pre[i+1] = pre[i] + arr[i];
    }

    ll l = 0, r = 0, ans = 0;
    while ( r < n ) {
        ll sumarr = pre[r+1] - pre[l];
        if (sumarr < x) {r++; continue;}
        if (sumarr > x){l++; continue;}
        ans += 1;
        r++;
    }

    cout << ans;
    return 0;
}
