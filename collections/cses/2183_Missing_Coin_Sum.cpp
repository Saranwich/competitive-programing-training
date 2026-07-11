// CSES 2183 — Missing Coin Sum  https://cses.fi/problemset/task/2183
// n <= 2e5, positive values. approach: greedy, sort ascending, track reach , O(n log n)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> arr(n); for (auto &i: arr) cin >> i;
    sort(arr.begin(), arr.end());
    ll reach = 0;
    for (ll r = 0; r < n; r++){
        if (arr[r] > reach+1) {
            break;
        }
        reach += arr[r];
    }

    cout << reach + 1;
    return 0;
}
