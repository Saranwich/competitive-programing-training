// Codeforces 2244A
// https://codeforces.com/contest/2244/problem/A
//
// Plan (fill BEFORE coding — the gate):
//   1. What am I asked to output?
//   2. Constraints -> complexity budget?
//   3. Idea in one sentence:
//   4. Edge cases (n=1, all same, empty, overflow?):

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n; cin >> n;
    string s; cin >> s; 
    ll cur = 0;ll max_val = 0;
    for (auto c: s){
        if (c == '#') cur ++;
        else {
            if (cur > max_val) max_val = cur;
            cur = 0;
        }
    } if (cur > max_val) max_val = cur;
    
    cout << (max_val+1) / 2 << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
