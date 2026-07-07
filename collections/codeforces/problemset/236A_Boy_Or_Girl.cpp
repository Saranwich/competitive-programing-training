#include <bits/stdc++.h>
using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int counter = 0;
    bool found[28] = {false};
    string s;
    int idx;
    cin >> s;
    for (auto c : s){
        idx = c - 'a';
        if (!found[idx]){
            counter++;
            found[idx] = true;
        }
    }

    cout << ((counter & 1)? "IGNORE HIM!" : "CHAT WITH HER!") << "\n";

    return 0;
}