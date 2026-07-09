// CSES 1640 — Sum_of_Two_Values  https://cses.fi/problemset/task/1640
// n <= 2e5. approach: hash_map/ two pointer, O(n log n)    (fill BEFORE coding)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x; cin >> n; cin >> x;
    vector<pair<ll, ll>> a(n,{0,-1});
    for (ll i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    ll l = 0, r = n-1;
    ll sum;
    while (l < r){
        sum = a[l].first + a[r].first;
        if (sum == x) {
            cout << a[l].second << " " << a[r].second;
            return 0;
        }else if (sum < x) {
            l++;
        }else {
            r--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
