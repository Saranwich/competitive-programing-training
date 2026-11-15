#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> used(26,0);
    ll l = 0, r = n-1;
    while (l < r) {
        char cl = s[l], cr = s[r];
        if (cl < cr) {
            for (char i = cr; i > cl; i--) {
                used[i - 'a'] = 1;
            }
        }
        if (cr < cl){
            for (char i = cl; i > cr ; i--){
                used[i - 'a'] = 1;
            }
        }
        l++;r--;       
    }

    ll counter = 0;
    for (auto s : used) counter+=s;
    cout << counter << "\n";
    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--){
        solve();
    }
    return 0;
}