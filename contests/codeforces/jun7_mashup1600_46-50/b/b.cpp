#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
    #define dbg(...)
#endif

#define int int64_t

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int,int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

const int INF = 2e16 + 100;
void solve(int cs) {
    int n, m, q;
    cin >> n >> m >> q;
    V<vi> a(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    V<vi> orr(n + 1, vi(m + 1));
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            orr[i][j] = orr[i - 1][j] | a[i][j];
        }
    }

    auto chk = [&](int L, int R, int reg) {
        int ans = -1;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int x = orr[mid][reg];
            if (L < x && x < R) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    };

    while (q--) {
        int k; cin >> k;
        set<int> regs;
        map<int, pii> eqs;

        bool f = 1;
        while (k--) {
            int reg, x;
            char c;
            cin >> reg >> c >> x;
            if (!eqs.count(reg)) eqs[reg] = {-INF, INF};
            auto& [l, r] = eqs[reg];
            if (c == '>') {
                l = max(l, x);
            }
            else {
                r = min(r, x);
            } 
            regs.insert(reg);

            if (l >= r) f = 0;
        }

        int ans = -INF;
        for (auto reg : regs) {
            auto& [l, r] = eqs[reg];
            if (l < r && abs(l - r) > 1) {

                int cur = chk(l, r, reg);
                if (cur == -1) f = 0;
                ans = max(cur, ans);

            } else f = 0;
        }

        for (auto reg : regs) {
            int val = orr[ans][reg];
            auto& [l, r] = eqs[reg];
            if (l < val && val < r);
            else f = 0;
        }

        if (f) cout << ans << endl;
        else cout << -1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
#ifdef DeBuG
    cin >> tc;
#endif
    for (int cs = 1; cs <= tc; cs++) solve(cs);
    return 0;
}