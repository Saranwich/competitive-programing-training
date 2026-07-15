// https://cses.fi/problemset/task/1619
// n < 2 * 10^5 : n log n need

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b, max_cus = -1e18, cur_cus = 0; cin >> n;
    map<ll,ll> change;
    for (auto i = 0; i < n; i++){
        cin >> a >> b;
        ++change[a];
        --change[b];
    }

    for (auto [k,i] : change){
        cur_cus += i;
        max_cus = (max_cus > cur_cus)? max_cus: cur_cus;
        //cout << max_cus << " " << cur_cus << "\n";
    }

    cout << max_cus;

    return 0;
}
