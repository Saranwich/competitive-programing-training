#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x,y,z,r;
    cin >> x >> y >> z;
    r = x+y+z;
    /*
    if (x - y - z >=0) {
        for (int i = 0; i < r; i++) {
            cout << "P";
        }
        return;
    }

    if (y - x - z >=0) {
        for (int i = 0; i < r; i++) {
            cout << "R";
        }
        return;
    }

    if (z - x - y >=0) {
        for (int i = 0; i < r; i++) {
            cout << "S";
        }
        return;
    }*/

    if (x>=y && x>=z){
        for (int i = 0; i < r; i++){
            cout << "P";
        }
        cout << "\n";
        return;
    }
    if (y>=x && y>=z){
        for (int i = 0; i < r; i++){
            cout << "R";
        }
        cout << "\n";
        return;
    }
    if (z>=x && z >= y){
        for (int i = 0; i < r; i++){
            cout << "S";
        }
        cout << "\n";
        return;
    }
    cout << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}