// CSES 1141 — Playlist  https://cses.fi/problemset/task/1141
// n <= 2e5. approach: two pointer , O(n log n)   (fill BEFORE coding)  [stretch]
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> k(n); for (auto &v : k) cin >> v;
    map<ll,ll> last;
    ll l = 0, ans = 0;
    for (ll r = 0; r < n; r++){
        if (last.count(k[r]) && last[k[r]] >=l) {
            l = last[k[r]] + 1;
        }
        last[k[r]] = r;
        ans = max(ans, r - l + 1);
    }

    cout << ans;

    return 0;
}
