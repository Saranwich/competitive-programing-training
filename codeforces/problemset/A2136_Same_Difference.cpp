#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; string s; 
    cin >> n >> s;
    char r_char = s[n-1];
    int counter = 0;
    for (int i = n-2; i >= 0 ; i--){
        if (s[i] != r_char) counter++;
    }
    cout << counter << "\n";
    return;
}  

int main (){

    ios:: sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)solve();
    return 0;
}