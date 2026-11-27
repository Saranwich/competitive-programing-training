#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve (){
    ll m; cin >> m;
    ll buffer;
    multiset<ll> odd;
    multiset<ll> even;
    ll sum_even = 0;

    for (auto i = 0 ; i < m; i++){
        cin >> buffer;
        if (buffer % 2 == 0 ) {
            sum_even += buffer;
        }else{
            odd.insert(buffer);
        }
    }
    if (odd.size() == 0) { cout << "0\n"; return;}
    else if (odd.size() == 1) { cout << sum_even + *(odd.begin()) << "\n"; return;}

    ll sum_odd = 0;
    ll n_odd =  (odd.size() + 1) / 2;
    for (auto i = 0; i < n_odd ; i++){
        sum_odd += *(odd.rbegin());
        odd.erase(--odd.end());
    }

    cout << sum_even + sum_odd << "\n";

}

int main (){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll T; cin >> T;
    while (T--){
        solve();
    }
}