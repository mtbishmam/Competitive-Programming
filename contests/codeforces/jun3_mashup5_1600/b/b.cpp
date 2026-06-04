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
	int n, AX, AY, BX, BY;
	cin >> n >> AX >> AY >> BX >> BY;
	vector<int> vx, vy;
	vx.push_back(AX); vx.push_back(BX);
	vy.push_back(AY); vy.push_back(BY);
	V<pii> points;
	vi px(n), py(n);
	for (int i = 0; i < n; i++) cin >> px[i];
	for (int i = 0; i < n; i++) cin >> py[i];
	for (int i = 0; i < n; i++) {
		int x = px[i], y = py[i];
		vx.push_back(x);
		vy.push_back(y);
		points.push_back({x, y});
	}

	sort(all(vx)); sort(all(vy));
	vx.erase(unique(all(vx)), vx.end());
	vy.erase(unique(all(vy)), vy.end());

	auto cx = [&](int x) { return lower_bound(all(vx), x) - vx.begin(); };
	auto cy = [&](int y) { return lower_bound(all(vy), y) - vy.begin(); };
	auto ucx = [&](int cx) { return vx[cx]; };
	auto ucy = [&](int cy) { return vy[cy]; };
	map<int, set<int>> mx;
	for (auto& [x, y] : points) {
		mx[cx(x)].insert(cy(y));
	}

	// This'll cause issues in the map to get min/max y
	// mx[cx(AX)].insert(cy(AY));
	// mx[cx(BX)].insert(cy(BY));

	auto dist = [&](int x1, int y1, int x2, int y2) {
		return abs(ucx(x1) - ucx(x2)) + abs(ucy(y1) - ucy(y2));
	};
	auto dist2 = [&](int cx) {
		int x = ucx(cx);
		int nx = vx[cx + 1]; // this shouldn't fail...
		return abs(nx - x);
	};

	V<V<int>> dp(sz(vx) + 5, vi(2, -1));
	auto f = [&](auto&& f, int cx, int cy, int k) { // 0 -> left, 1 -> right
		if (ucx(cx) == BX) return abs(ucy(cy) - BY);
		auto& ret = dp[cx][k];
		if (~ret) return ret;
		ret = INF;
		// max_right
		int nyr = *mx[cx].rbegin();
		// min left
		int nyl = *mx[cx].begin();
		if (cy >= max(nyl, nyr)) { // go left only
			ret = dist(cx, cy, cx, nyl) + dist2(cx) + f(f, cx + 1, nyl, 0);
		}
		else if (cy <= min(nyl, nyr)) { // go right only
			ret = dist(cx, cy, cx, nyr) + dist2(cx) + f(f, cx + 1, nyr, 1);
		}
	 	else {

			// going left
			ret = min(ret, dist(cx, cy, cx, nyl) + dist(cx, cy, cx, nyr) * 2 + dist2(cx) + f(f, cx + 1, nyl, 0));
			// going right
			ret = min(ret, dist(cx, cy, cx, nyr) + dist(cx, cy, cx, nyl) * 2 + dist2(cx) + f(f, cx + 1, nyr, 1));

		}
		return ret;
	};
	cout << abs(AX - ucx(mx.begin()->first)) + f(f, 1, cy(AY), 0) << endl;

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