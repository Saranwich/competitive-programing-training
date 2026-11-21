#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

ll get_max (ll M){
    ll a = (M + 3) / 3;
    ll max_dam = (a * M) + (((3 * a) - (3 * a * a)) / 2);
    return max_dam;
}

void solve(){
    ll x; cin >> x;
    ll l = 1, r = 500;
    ll mid;
    ll max_mid;

    if (x <= 4) {
        cout << x << "\n";
        return;
    }

    while (l < r){
        mid = l + ((r - l) / 2);
        
        max_mid = get_max(mid);

        if (max_mid >= x) { r = mid;}
        else {l = mid + 1;} 
    }
    cout << l << "\n";
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T; cin >> T;
    while (T--){
        solve();
    }

    return 0;
}