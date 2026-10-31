#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    string p,q; cin >>p >> q;

    if (m > n){
        cout << "NO\n";
        return;
    }

    vector<int> str (26,0);
    for (auto c : p){
        str[c - 'a']++;
    }
    for (auto c : q){
        if (str[c - 'a'] == 0){
            cout << "NO\n";
            return;
        }
        str[c - 'a']--;
    }
    if (str['s' - 'a'] != 1 || str['i' - 'a'] != 1 || str['x' - 'a'] != 1){
        cout << "NO\n";
        return;
    }
    int count = 0;
    for (auto i : str){
        count+=i;
    }
    if (count-3 != 0){
        cout << "NO\n";
            return;
    }
    
    
    cout << "YES\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}