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
	int n, l, r; cin >> n >> l >> r;
	vi a(n), b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (l <= a[i] && a[i] <= r) {
			b.push_back(a[i]);
		}
	}
	vi p = a;
	n += 2;
	a.push_back(l); a.push_back(r);
	b.push_back(l); b.push_back(r);
	sort(all(a)); sort(all(b));
	auto chk = [&](int x) {
		int ret = 0;
		for (int i = 0; i < sz(p); i++) {
			ret += abs(x - p[i]);
		}
		return ret;
	};
	int amid = a[sz(a) / 2];
	int amid2 = (sz(a) / 2 - 1 >= 0 ? a[sz(a) / 2 - 1] : INF);

	auto bit = lower_bound(all(b), amid);
	int ans = INF;
	if (bit != b.end()) ans = min(ans, chk(*bit));
	bit++; if (bit != b.end()) ans = min(ans, chk(*bit));

	auto bit2 = lower_bound(all(b), amid2);
	if (bit2 != b.end()) ans = min(ans, chk(*bit2));
	bit2++; if (bit2 != b.end()) ans = min(ans, chk(*bit2));


	int bmid = b[sz(b) / 2];
	int bmid2 = (sz(b) / 2 - 1 >= 0 ? b[sz(b) / 2 - 1] : INF);
	ans = min(ans, chk(bmid));
	ans = min(ans, chk(bmid2));
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