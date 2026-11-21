#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

ll get_max (ll M){
    ll a = (2 * M + 3) / 6;
    ll max_dam = (a * M) + (((3 * a) - (3 * a * a)) / 2);
    return max_dam;
}

void solve(){
    ll x,y,m; cin >> x >> y >> m;
    string s ; cin >> s;
    ll i = 0;
    ll max_amount = x + y;
    while (!(x <= 0 && y <= 0) && (i < m)){
        if (*(s.begin() + i) == '+'){
            if (y>0){
                y+=1;
            }else if (x > 0){
                x-=1;
                y+=1;
            }
        }else{
            if (y > 1) {
                y-=1;
                x+=1;
            }else if (x > 0){
                x-=1;
            }else{
                y-=1;
                x+=1;
            }
        }
        if (max_amount < x + y){
            max_amount = x + y;
        }        
        i++;
        
    }
    cout << max_amount << "\n";

    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T; cin >> T;
    while (T--){
        solve();
    }

    return 0;
}