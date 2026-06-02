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

using vb = vector<bool>;

void solve(int cs) {
	int n, k; 
	cin >> n >> k;

	V<V<int>> g(n + 1);
	V<V<pii>> lvl(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vb vis(n + 1);
	vi dep(n + 1), szz(n + 1), delta;
	auto f = [&](auto&& f, int u, int d) -> void {
		vis[u] = 1;
		szz[u] = 1;
		dep[u] = d;
		for (auto& v : g[u]) {
			if (vis[v]) continue;
			f(f, v, d + 1);
			szz[u] += szz[v];
		}
		lvl[dep[u]].push_back({-szz[u], u});
		delta.push_back(d - (szz[u] - 1));
	};
	f(f, 1, 0);
	sort(all(delta));
	int ans = 0;
	while (k) ans += delta.back(), delta.pop_back(), k--;
	cout << ans << endl;
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