#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string f;
    cin >> f;
    int freq[3] = {0,0,0};
    for (auto i : f){
        if (i == '+') continue;
        freq[i-'1']++;
    }
    string ans = "";
    string one = "1+";
    string two = "2+";
    string three = "3+";
    for (auto i{0}; i<freq[0]; i++) ans+=one;
    for (auto i{0}; i<freq[1]; i++) ans+=two;
    for (auto i{0}; i<freq[2]; i++) ans+=three;    
    ans = ans.substr(0,2*(freq[0] + freq[1] + freq[2]) - 1);
    cout << ans;
    return 0;
}