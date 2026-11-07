#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    set<ll> traffic;
    multiset<ll> length;
    ll x, n, buf; cin >> x >> n;
    vector<ll> ans; ans.reserve(n);
    traffic.insert(x); traffic.insert((ll)0);
    length.insert(x);

    for(auto i = 0; i < n; i++){
        cin >> buf;
        auto it = traffic.upper_bound(buf);
        auto r = *it;
        auto l = *(--it);
        length.erase(length.find(r-l));
        length.insert(buf - l); 
        length.insert(r - buf);
        traffic.insert(buf);

        cout << *length.rbegin() << " ";
    }

    return 0;
}