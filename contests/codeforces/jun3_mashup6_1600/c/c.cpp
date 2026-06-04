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

const int INF = 1e16;
void solve(int cs) {
	int n; cin >> n;
	vi a(n + 5), c(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	// a[n + 1] = INF;
	// V<V<int>> dp(n + 5, vi(n + 5, -1)); // i, j -> prev mn pos
	// auto f = [&](auto&&f, int i, int j) -> int {
	// 	if (i > n) return 0;
	// 	auto& ret = dp[i][j];
	// 	if (~ret) return ret;

	// 	ret = INF;
	// 	if (a[j] <= a[i]) {
	// 		ret = f(f, i + 1, i);
	// 	}
	// 	ret = min(ret, c[i] + f(f, i + 1, j));
	// 	return ret;
	// };
	// cout << f(f, 1, 0) << endl;

	vi dp(n + 5, -1);
	auto f = [&](auto&&f, int i) -> int {
		if (i > n) return 0;
		auto& ret = dp[i];
		if (~ret) return ret;
		ret = c[i];
		for (int j = i + 1; j <= n; j++)
			if (a[i] <= a[j]) ret = max(ret, c[i] + f(f, j));
		return ret;
	};

	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, f(f, i));
	cout << accumulate(all(c), (int)0) - mx << endl;
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