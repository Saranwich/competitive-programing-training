#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    pair<int,int> p = {vals[0], vals[n - 1]};
    if (p.first == -1 || p.second == -1) {
        int edge_number = max(max(p.first,p.second),0);
        vals[0] = edge_number; vals[n-1] = edge_number;
    }
    
    cout << abs(vals[0] - vals[n-1]) << "\n" ;

    for (auto a : vals){
        cout << ((a == -1)? 0 : a) << " ";
    }
    
    cout << "\n";
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t = 0; t < T; t++) solve();
    return 0;
}
