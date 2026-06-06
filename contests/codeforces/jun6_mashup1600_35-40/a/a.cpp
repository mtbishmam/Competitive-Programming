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

void solve(int cs) {
    int n; cin >> n;

    V<V<int>> g(n + 1);
    vector<pair<int,int>> edges;

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        edges.push_back({x, y});
    }

    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    vi deg(n + 1);

    set<pii> s;
    for (int i = 1; i <= n; i++) {
        deg[i] = sz(g[i]);
        s.insert({deg[i], i});
    }

    int best = 0;

    // adjacent pairs
    for (auto &[u, v] : edges) {
        best = max(best, deg[u] + deg[v] - 1);
    }

    // non-adjacent pairs
    for (int u = 1; u <= n; u++) {
        vector<pii> removed;

        auto erase_vertex = [&](int x) {
            auto it = s.find({deg[x], x});
            if (it != s.end()) {
                removed.push_back(*it);
                s.erase(it);
            }
        };

        erase_vertex(u);
        for (int v : g[u]) erase_vertex(v);

        if (!s.empty()) {
            auto [d, v] = *s.rbegin();
            best = max(best, deg[u] + d);
        }

        for (auto &p : removed) {
            s.insert(p);
        }
    }

    cout << best - 1 << '\n';
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