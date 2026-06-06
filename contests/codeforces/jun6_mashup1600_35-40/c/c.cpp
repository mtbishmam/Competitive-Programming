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

const int MOD = 998244353;
void solve(int cs) {
	int n; cin >> n;
	vi a(n); for (auto& i : a) cin >> i;
	reverse(all(a)); int z = 0;
	while (sz(a) && a.back() == 0) a.pop_back(), z = 1;
	if (z) a.push_back(0); reverse(all(a));
	n = sz(a);

	V<vi> dp(n, vi(2, -1));
	auto f = [&](auto&& f, int i, int j) -> int {
		if (i == n) return 1;
		auto& ret = dp[i][j];
		if (~ret) return ret;

		ret = 0;
		if (j == 0) { // prev liar
			if (i - 2 >= 0 && a[i - 2] + 1 == a[i]) {
				ret = f(f, i + 1, 1);
			} else { // 2nd idx
				if (i == 1 && a[i] == 1) ret = f(f, i + 1, 1);
			}
		} else { // prev honest
			ret = f(f, i + 1, 0); // he lies
			if (i - 1 >= 0 && a[i - 1] == a[i]) {
				ret = (ret + f(f, i + 1, 1)) % MOD;
			}
		}
		return ret;
	};
	int ans = 0;
	if (a[0] == 0) {
		ans = (f(f, 1, 0) + f(f, 1, 1)) % MOD;
	} else ans = f(f, 1, 0);
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