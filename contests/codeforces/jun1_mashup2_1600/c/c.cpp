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

const int INF = 1e15;

void solve(int cs) {
	int n, k, m = 32;
	cin >> n >> k;
	V<V<int>> a(n + 5, vi(m + 5));
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i][0] = x;
		int j = 1;
		do {
			x /= 2;
			a[i][j++] = x;
		} while (x);
	}

	V<V<int>> dp(n + 5, vi(m + 5, -INF));
	auto f = [&](auto&& f, int i, int j) -> int {
		if (i == n) return 0;
		if (j == m) return 0;
		auto& ret = dp[i][j];
		if (ret != -INF) return ret;
		ret = a[i][j] - k + f(f, i + 1, j);
		ret = max(ret, a[i][j + 1] + f(f, i + 1, j + 1));
		return ret;
	};
	cout << f(f, 0, 0) << endl;
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