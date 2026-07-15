// https://cses.fi/problemset/task/1164
// 2 * 10 ^ 5 : n log n needed

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ll amt_rooms = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> rooms;
    vector<array<ll,3>> cus(n);
    for (ll i = 0; i < n; i++){ cin >> cus[i][0] >> cus[i][1]; cus[i][2] = i; }
    sort(cus.begin(), cus.end());

    vector<ll> ans(n);
    for (auto &[a,d,idx]: cus) {
        if (rooms.empty() || rooms.top().first >= a) {
            rooms.push({d, ++amt_rooms});
            ans[idx] = amt_rooms;
        }else{
            ll r = rooms.top().second;
            rooms.pop();
            rooms.push({d,r});
            ans[idx] = r;
        }
    }

    sort(cus.begin(), cus.end(), [](auto &x, auto &y){
        return x[2] < y[2];
    });
    cout << amt_rooms << "\n"; for (auto r : ans){cout << r << " ";}
}