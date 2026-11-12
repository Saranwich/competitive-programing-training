#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve(){
    ll n; cin >> n;
    ll switch_count = 0;
    bool is_red = false;
    string inp; cin >> inp;
    for (auto &s : inp){
        if ( (s == 'R' && is_red) || (!(is_red) && s == 'B')) {
            switch_count++;
            continue;
        }
        is_red = !(is_red);
    }
    cout << switch_count << "\n";
    
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