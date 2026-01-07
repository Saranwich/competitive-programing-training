#include<bits/stdc++.h>
using namespace std;

void solve (){
    int n,k, stack = 0;
    cin >> n >> k;

    vector<int> arr(n,0);
    vector<int> free_idx;free_idx.reserve(n);
    vector<int> rule_idx;rule_idx.reserve(n);
    string s; cin >> s;

    for (auto i{0}; i < n; i++){
        if (s[i] == '0') {
            stack = 0;
            free_idx.push_back(i);
        }else{
            stack++;
            if (stack >= k) {
                cout << "NO\n";
                return;
            }
            rule_idx.push_back(i);
        }
    }
    int opr = 1;
    for (auto i : rule_idx){
        arr[i] = opr;
        opr++;
    }

    for (auto i : free_idx){
        arr[i] = opr;
        opr++;
    }

    cout << "YES\n";
    for (auto p : arr) {
        cout << p << " ";
    } 
    cout << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t{0}; t < T; t++) solve();

    return 0;
}