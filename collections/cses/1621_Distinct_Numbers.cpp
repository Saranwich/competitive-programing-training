// CSES 1621 — Distinct_Numbers  https://cses.fi/problemset/task/1621
// n ≤ 2 * 10 ^ 5, so O(n log n) needed
// check(x): bool , monotonic because ___   (fill BEFORE coding — for BS problems)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll found = 0;
    ll a,n; cin >> n;
    set<ll> founded;
    for (auto i = 0; i < n; i++){
        cin >> a;
        if (founded.count(a)) continue;
        founded.insert(a);
        found++;
    }
    
    cout << found;

    return 0;
}
