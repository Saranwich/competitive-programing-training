// CSES 1661 — Subarray Sums II  https://cses.fi/problemset/task/1661
// n <= 2e5, values CAN BE NEGATIVE. Count subarrays with sum == x.
// approach: map + prefix , O(n log n)   (fill BEFORE coding — negatives break the window => prefix + map)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x; cin >> n >> x;

    map<ll,ll> seen;
    seen[0] = 1;
    ll run = 0, ans = 0;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        run += a;
        ans += seen[run - x];
        seen[run]++;
    }

    cout << ans;
    return 0;
}
