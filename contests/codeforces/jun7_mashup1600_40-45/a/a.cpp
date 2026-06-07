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

template<typename T>
struct segtree {
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; } // any associative fn
    V<int> s; int n;
    segtree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    void add(int pos, T delta) {
        update(pos, s[pos + n] + delta);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve(int cs) {
    int n, k; cin >> n >> k;
    vi a(n), b(n), points;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        points.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        points.push_back(b[i]);
    }
    sort(all(points));
    points.erase(unique(all(points)), points.end());
    auto c = [&](int p) { return lower_bound(all(points), p) - points.begin(); };
    segtree<int> active(sz(points) + 5);

    vi endings[sz(points) + 5];
    for (int i = 0; i < n; i++) {
        a[i] = c(a[i]); b[i] = c(b[i]);
        endings[b[i]].push_back(a[i]);
        // active.update(a[i], active.query(a[i], a[i] + 1) + 1);
        active.add(a[i], 1);
    }

    int ans = 0;
    for (int p = 0; p < sz(points); p++) {
        int ck = active.query(0, p);
        if (ck <= k) {
            int cn = active.query(0, sz(points));
            ans = max(ans, cn * points[p]);
        }
        // for (auto& end : endings[p]) active.update(end, active.query(end, end + 1) - 1);
        for (auto& end : endings[p]) active.add(end, -1);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
// #ifdef DeBuG
    cin >> tc;
// #endif
    for (int cs = 1; cs <= tc; cs++) solve(cs);
    return 0;
}