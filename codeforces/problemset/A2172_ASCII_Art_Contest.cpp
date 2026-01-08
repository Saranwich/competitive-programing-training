#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (abs(a-b) >= 10 || abs(a-c) >= 10 || abs(b-c) >= 10) 
    {
        cout << "check again\n";
        return ;
    }

    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    cout << "final " << b << "\n";
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}