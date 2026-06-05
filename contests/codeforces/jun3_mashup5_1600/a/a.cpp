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
	int n, m; cin >> n >> m;
	V<V<int>> a(n + 5, vi(m + 5));
	int ones = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			ones += a[i][j];
		}
	}
	int req = ones / 2;
	int mx = req * (ones - req);

	V<V<int>> suf(n + 5, vi(m + 5));
	for (int j = 1; j <= m; j++) {
		for (int i = n; i >= 1; i--) {
			suf[i][j] += a[i][j] + suf[i + 1][j];
		}
	}

	string ans;
	auto f = [&](auto&& f, int x, int y) {
		if (y > m) {
			while (sz(ans) < n + m) ans += 'D';
			return;
		}
		if (x > n) {
			while (sz(ans) < n + m) ans += 'R';
			return;
		}
		int ones = suf[x][y];
		if (ones <= req) { // go right
			req -= ones;
			ans += 'R';
			f(f, x, y + 1);
		} else {
			ans += 'D';
			f(f, x + 1, y);
		}
	}; f(f, 1, 1);
	cout << mx << endl;
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