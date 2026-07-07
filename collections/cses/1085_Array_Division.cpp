// CSES 1085 — Array_Division  https://cses.fi/problemset/task/1085
// n ≤ 2*10^5, so O(n log n) needed
// check(x): bool , monotonic because monotonic because it always false at first until it turn into True and never turn back to false again (checking by maximum exceeding sum)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> &x, ll k, ll value){
    ll pieces = 1, cur = 0;
    for (auto i: x){
        if (i > value) return false;
        cur += i;
        if (cur > value){
            pieces++;
            cur = i;
        }
    }
    return pieces <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ll k; cin >> k;
    vector<ll> x(n); for(auto &i:x) cin >> i;

    ll lo = 0, hi = 2e18;
    ll mid = lo + (hi-lo)/2;
    while (lo < hi) {
        if (check(x,k,mid)) hi = mid; else lo = mid + 1;
        mid = lo + (hi-lo)/2;
        
    }
    cout << lo;

    return 0;
}
