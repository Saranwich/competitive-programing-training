#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, mins;
    cin >> n >> mins;
    int cur_min = 0;
    int score = 0;
    int state = 0;

    int command_min, command_state;
    for (auto i = 0; i < n; i++){
        cin >> command_min >> command_state;
        bool is_same_type = ((command_min & 1) == (cur_min & 1));
        bool is_same_state = (command_state == state);
        score += (command_min - cur_min) -
                ((is_same_state ^ is_same_type)? 1:0);
        cur_min = command_min;
        state = command_state;
    }    
    score += (mins-cur_min);
    cout << score << "\n";

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t = 0; t < T; t++){
        solve();
    }

    return 0;
}