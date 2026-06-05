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

struct segtree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); }
	vector<T> s; int n;
	segtree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;) 
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
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
	int n; cin >> n;
	vi a(n); for (auto& i : a) cin >> i;
	// vi a(n + 1), pos(n + 1);
	// for (int i = 1; i <= n; i++) {
	// 	cin >> a[i];
	// 	pos[a[i]] = i;
	// }

	// vi dp(n + 5, -1);
	// segtree tree(n + 5);
	// for (int x = n; x >= 1; x--) {
	// 	int p = pos[x];
	// 	dp[p] = 1;
	// 	int l = 1, r = p;
	// 	dp[p] = max(dp[p], 1 + tree.query(l, r));
	// 	tree.update(p, dp[p]);
	// }

	// int ans = 0;
	// vi dp(n, -1);
	// auto f = [&](auto&& f, int i) -> int {
	// 	if (i == n) return 0;
	// 	auto& ret = dp[i];
	// 	if (~ret) return ret;

	// 	ret = 1; 
	// 	int op = 0;
	// 	if (i > 1 && min(a[i - 1], a[i - 2]) > a[i]) op = 2;
	// 	else if (i > 1 && max(a[i - 1], a[i - 2]) > a[i]) op = 1;

	// 	ans += (ret = 1 + op);
	// 	return ret;
	// };
	// for (int i = 2; i < n; i++) 
	// 	f(f, i);
	// // cout << accumulate(all(dp), (int)0) << endl;
	// cout << ans << endl;

	// {
	// 	for (int n = 3; n <= 6; n++) {
	// 		vi a(n); iota(all(a), 1);
	// 		do {
	// 			bool f = 1;
	// 			for (int i = 2; i < n; i++) {
	// 				f &= (max(a[i - 2], a[i - 1]) > a[i]);
	// 			}
	// 			if (f) dbg(a);
	// 		} while(next_permutation(all(a)));
	// 		dbg();
	// 	}
	// }

	vi dp(n, -1); // dp[i] = sum of LDS ending at i
	auto f = [&](auto&& f, int i) -> int {
		if (i >= n or i < 0) return 0;
		auto& ret = dp[i];
		if (~ret) return ret;
		ret = 1; // len 1 LDS
		if (i - 1 >= 0 and a[i - 1] > a[i]) ret += f(f, i - 1) + i;
		else ret += f(f, i - 1);
		return ret;
	};
	int ans = 0;
	for (int i = 0; i < n; i++) ans += f(f, i);
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