#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n,k,num1, num2;

    cin >> n >> k;
    num1 = n; num2 = n;
    if (num1 == k) {cout << "0\n";return;}
    int time = 0;

    while (num2 > k || num1 > k){
        num1 = num1 >> 1;
        num2 = (num2 + 1) >> 1;
        
        time++;
        if (num1 ==k || num2==k) {
            cout << time << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}