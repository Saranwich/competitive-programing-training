// https://cses.fi/problemset/task/1084
// n log n need

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k; cin >> n >> m >> k;
    vector<ll> app(n);for (auto &a: app) cin >> a; sort(app.begin(), app.end());
    vector<ll> apt(m);for (auto &a: apt) cin >> a; sort(apt.begin(), apt.end());

    ll app_p=0, apt_p = 0, ans = 0;
    while (app_p < n && apt_p < m){
        if (abs(app[app_p] - apt[apt_p]) <= k) {
            ans++;app_p++;apt_p++;
        }else{
            if (app[app_p] > apt[apt_p]) apt_p++; else app_p++;
        }
    }

    cout << ans;
}