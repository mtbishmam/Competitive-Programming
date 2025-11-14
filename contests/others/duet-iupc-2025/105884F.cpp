// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n1, m1;
    cin >> n1 >> m1;
    int n, m;
    n = max(n1, m1);
    m = min(n1, m1);
    ll ans[n][m];
    //cout<<"n= "<<n<<" m= "<<m<<endl;
    int cur = 1;
    int cnt = m;
    set<ll>ans2;
    for (int i = 1;i <= m;i++) {
        ans2.insert(i);
    }
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < cnt;j++) {
            ans[i][j] = cur;
        }
        cur++;
        for (int j = cnt;j < m;j++) {
            ans[i][j] = cur;
            cur++;
        }
        cnt--;
    }
    cnt = 0;
    for (int i = 0;i < m;i++) {
        for (int j = m;j < min(n, m + cnt);j++) {
            ans[j][i] = 1;
        }
        for (int j = min(n, m + cnt);j < n;j++) {
            ans[j][i] = cur;
            cur++;
        }
        ans2.insert(n - cnt);
        cnt++;
    }
    // cout << ans2.size() << endl;
    set<int>a;
    for (int i = 0;i < n;i++) {
        set<ll>a2;
        for (int j = 0;j < m;j++) {
            a2.insert((ll)ans[i][j]);
        }
        a.insert((int)a2.size());
    }
    for (int i = 0;i < m;i++) {
        set<int>a2;
        for (int j = 0;j < n;j++) {
            a2.insert((int)ans[j][i]);
        }
        a.insert((int)a2.size());
    }
    int szans = a.size();
    assert(min(2 * min(n1, m1), max(n1, m1)) == szans);
    cout << a.size() << endl;
    if (n1 == n) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                cout << ans[j][i] << " ";
            }
            cout << endl;
        }
    }
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}