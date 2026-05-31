#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
    #define dbg(...)
#endif

// #define int int64_t

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int, int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

void solve(int cs) {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << "YES\n";
        return;
    }

    bool final = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && i + 2 < n && s[i + 1] == '0' && s[i + 2] == '1') {
            if (i - 1 >= 0 && s[i - 1] == '0') i += 2;
            else if (i + 3 < n && s[i + 3] == '0') i += 4;
            else final = 0;
        }
    }
    if (final) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for (int cs = 1; cs <= tc; cs++) solve(cs);
    return 0;
}
