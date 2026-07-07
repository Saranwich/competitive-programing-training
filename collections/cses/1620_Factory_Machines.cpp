// CSES 1620 — Factory_Machines  https://cses.fi/problemset/task/1620
// n ≤ 2e5, so O(n log n) needed
// check(x): bool , monotonic because it always false at first until it turn into True and never turn back to false again
using namespace std;
using ll = long long;

bool check(vector<ll> &k, ll t, ll target){
    ll time = 0;
    for (auto i : k){
        time += t/i;
        if (time >= target) return 1;
    }
    return time >= target;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,t; cin >> n; cin >> t;
    vector<ll> k(n); for (auto &i:k) cin >> i;

    ll lo = 0, hi = 2e18;
    ll mid = lo + (hi-lo)/2;

    while (lo < hi){
        if (check(k,mid,t)) hi = mid; else lo = mid+1;
        mid = lo + (hi-lo)/2;
    }

    cout << lo;

    return 0;
}
