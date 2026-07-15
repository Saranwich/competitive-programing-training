// https://cses.fi/problemset/task/1630
// n = 2 * 10^5 -> n log n needed

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    ll a, d;
    ll sum_duration = 0;
    vector<pair<ll, ll>> tasks; tasks.reserve(n);
    for ( auto i = 0; i < n; i++){
        cin >> a >> d;
        tasks.push_back({a,d});
    }

    ll score = 0;

    sort(tasks.begin(), tasks.end());
    for (auto &[a,d]: tasks){
        sum_duration += a;
        score += d - sum_duration;
    }

    cout << score ;

}