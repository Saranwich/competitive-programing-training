#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> char_counter1 (26,0);
    vector<int> char_counter2 (26,0);
    vector<int> char_found_idx; char_found_idx.reserve(26);

    string a;
    string b;
    cin >> a >> b;

    for (auto i = 0; i < n; i++){
        char_counter1[a[i] - 'a']++;
        char_counter2[b[i] - 'a']++;
    }

    for (auto i = 0; i < n; i++){
        if (char_counter1 != char_counter2){
            cout << "NO\n" ;
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t{0}; t < T ; t++){
        solve();
    }

    return 0;
}