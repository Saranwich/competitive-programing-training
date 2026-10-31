#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int sum_middle = 0; 
    int l_edge, r_edge; cin >> l_edge;
    vector<int> middle (n-2,0);
    for (auto i = 0; i < n-2; i ++){
        cin >> middle[i];
        sum_middle += middle[i];
    }
    cin >> r_edge;
    
    if (sum_middle+ l_edge + r_edge == n){
            cout << "-1\n";
            return;
    }

    if (sum_middle == n - 2){// minus the l_edge and the r_edge, so this is mean need to start from edge
        if (l_edge >= 2 || r_edge >= 2){
            cout << l_edge + r_edge - sum_middle - 1 << "\n";
            return;
        }
    } //

    //this is not we know that here is start from middle
    cout << l_edge + r_edge + sum_middle - 1 <<  "\n";
    
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}