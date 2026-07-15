// 2 * 10 ^ 5 : n log n
// sort -> logn, search -> n -> n + logn -> n
//https://cses.fi/problemset/task/1629
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pair<ll,ll>> movies (n); movies.reserve(n);
    ll a,b;
    for (auto i = 0; i < n; i++){
        cin >> a >> b;
        movies[i] = {a,b};
    }

    sort(movies.begin(),movies.end(), [](pair<ll, ll>& x, pair<ll, ll>& y){
        return tie(x.second, x.first) < tie(y.second, y.first);
    });

    ll time = 0;ll ans = 0;
    for (auto &[s, e]: movies){
        if (time > s) continue;
        ans++;
        time = e;
    }

    cout << ans;
}