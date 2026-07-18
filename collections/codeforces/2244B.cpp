// Codeforces 2244B
// https://codeforces.com/contest/2244/problem/B
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
    ll spare = 0;
    vector<ll> V(n) ; for (auto &v: V) cin >> v;
    for (ll i = 1; i <= n; i++){
        ll have = spare + V[i-1];
        if (have < i){
            cout << "NO\n";
            return;
        }
        spare = have - i;
    }
    cout << "YES\n";return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
