#include <bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int buf;
    multiset<int> tickets;
    vector<int> cus;
    vector<int> ans;

    for (auto i = 0; i < n; i++) {cin >> buf; tickets.insert(buf);}
    for (auto i = 0; i < k; i++) {cin >> buf; cus.push_back(buf);} 

    for (auto c : cus){
        auto it = tickets.upper_bound(c);
        if (it == tickets.begin()) {
            cout << "-1\n";
            continue;
        }
        else{
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
    
    return 0;
}