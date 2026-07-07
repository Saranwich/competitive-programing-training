#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n;
    cin >> n;

    vector<bool> colors_found (1000,false);
    vector<int> colors; colors.reserve(n);
    
    int temp;
    for (auto i{0} ; i < n; i++){
        cin >> temp;
        if (colors_found[temp]) continue;
        colors_found[temp] = true;
        colors.push_back(temp);
    }

    int distinct_color = colors.size();
    while (!(colors_found[distinct_color])){
        colors_found[distinct_color] = true;
        distinct_color++;
    }
    cout << distinct_color << "\n";
    

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t = 0; t < T; t++) solve();

    return 0;
}