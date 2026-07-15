// 2 * 10 ^ 5 : n log n
// sort -> logn + search
//https://cses.fi/problemset/task/1632
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll k,n; cin >> n >> k;
    vector<pair<ll,ll>> movies(n);

    ll s,e;
    for (auto i = 0; i < n; i++) {cin >> s >> e; movies[i] = {s, e};}
    //for (auto &v: movies) cout << v.first << " - " << v.second << "\n";
    sort(movies.begin(), movies.end(), [](pair<ll,ll>& x, pair<ll,ll>& y){
        return tie(x.second,x.first) < tie(y.second, y.first);
    });
    //for (auto &v: movies) cout << v.first << " - " << v.second << "\n";
    ll ans = 0;
    multiset<ll> freeAt; for (auto i = 0 ; i < k; i++) freeAt.insert(0);
    //for (auto s: freeAt) cout << s << " "; cout << "\n";

    for (auto &[s,e] : movies){
        auto it = freeAt.upper_bound(s);
        if (it == freeAt.begin()) continue;
        --it;
        freeAt.erase(it);
        freeAt.insert(e);
        //for (auto s: freeAt) cout << s << " "; cout << "\n";
        ans++;
    }
    cout << ans;
}
