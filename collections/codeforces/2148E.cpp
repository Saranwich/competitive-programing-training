#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve (){
    ll n, k; cin >> n >> k;
    vector<ll> cnt(n + 1, 0);
    vector<ll> window(n + 1, 0);
    vector<ll> limit(n + 1, 0);
    vector<ll> a(n);

    for (auto &x : a) {
        cin >> x;
        cnt[x]++;
    }

    for (ll i = 1; i <= n; i++) {
        if (cnt[i] % k == 0) {
            limit[i] = cnt[i] / k;
        } else {
            cout << "0\n";
            return;
        }
    }

    ll ans = 0;
    ll l = 0;
    for (ll r = 0; r < n; r++){
        window[a[r]]++;

        while (window[a[r]] > limit[a[r]]){
            window[a[l]]--;
            l++;
        }

        ans+= r-l + 1;
    }
    cout << ans << "\n";

}

int main (){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T; cin >> T; while (T--) solve();
}