#include<bits/stdc++.h>
using namespace std;

void solve ()
{
    int n,x,y;
    string s;
    cin >> n >> x >> y >> s;
    int c8 = 0, c4 = 0;
    for (auto c : s) (c - '4')? c8+=1 : c4+=1;
    cout << (c8 >= max(abs(x),abs(y)) ||
            (max(abs(x) - c8,0) + max(abs(y) - c8, 0) <= c4)?
            "YES\n": "NO\n");
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}