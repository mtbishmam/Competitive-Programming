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

const int INF = 1e18;
struct segtree {
	typedef int T;
	static constexpr T unit = -INF;
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
	int n, h;
	cin >> n >> h;
	vi a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = h - a[i];
	}

	vi mx(n);
	for (int i = 0; i < n; i++) {
		int cur = b[i];
		int cmn = b[i];
		for (int l = i - 1; l >= 0; l--) {
			cmn = min(cmn, b[l]);
			cur += cmn;
			if (!cmn) break;
		}
		cmn = b[i];
		for (int r = i + 1; r < n; r++) {
			cmn = min(cmn, b[r]);
			cur += cmn;
			if (!cmn) break;
		}
		mx[i] = cur;
	}

	segtree tree(n);
	for (int i = 0; i < n; i++) { 
		tree.update(i, mx[i]);
	}
	dbg(mx);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cur = mx[i];
		int cmx = a[i];
		tree.update(i, 0);
		for (int l = i - 1; l >= 0; l--) {
			cmx = max(cmx, a[l]);
			tree.update(l, b[l] - (h - cmx));
			if (cmx == h) break;
		}
		cmx = a[i];
		for (int r = i + 1; r < n; r++) {
			cmx = max(cmx, a[r]);
			tree.update(r, b[r] - (h - cmx));
			if (cmx == h) break;
		}
		ans = max(ans, cur + tree.query(0, n));

		for (int i = 0; i < n; i++) {
			cerr << tree.query(i, i + 1) << " ";
		} cerr << endl;

		for (int l = i - 1; l >= 0; l--) {
			tree.update(l, b[l]);
		}
		for (int r = i + 1; r < n; r++) {
			tree.update(r, b[r]);
		}
		tree.update(i, b[i]);
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