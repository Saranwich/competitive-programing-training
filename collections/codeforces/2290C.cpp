#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve(){
    ll n; cin >> n;
    multiset<ll> s;
    if (n <= 3) {
        cout << "1\n"; return;
    }
    ll num_king = 0, num_queen = 0;
    ll buf; for (auto i = 0; i < n; i++) {cin >> buf; s.insert(buf);}
    //for (auto i = 0; i < n; i++) {cout << *(s.rbegin());}
    ll king = *(s.rbegin());
    num_king = s.count(king);

    if (num_king == 2){
        
    }


    ll queen = *(--s.lower_bound(king));
    num_queen = s.count(queen);
    // if there is 2 king

    if ()
    
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