#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve (){

    ll n,k; cin >> n >> k;
    vector<ll> a(n,0);
    vector<ll> window(n+1,0);
    for (auto &v: a) cin >> v;

    for (ll i = 0; i < n - k; i++){
        window[a[i]]++;
    }
    ll ans = 0;
    for (ll i = 0 ; i + (n - k) < n; i++){
        window[a[i + (n - k)]]++;
        if (window[a[i]] == n-k+1){
            ans++;
        }
        window[a[i]]--;
    }   

    cout << ans << "\n";
    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T; cin >> T; while (T--) solve();
    return 0;
}