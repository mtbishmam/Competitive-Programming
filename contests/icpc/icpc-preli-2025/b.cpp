#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int a, v, l, n;
    cin >> a >> v >> l >> n;
    if (v == 1) {
        cout << "NO" << endl;
        return;
    }
    if (a <= n) {
        cout << "NO" << endl;
        return;
    }
    if (v <= n) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}