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

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto sq = [&](int x) { return x * x; };
	auto sq2 = [&](pii& a, pii& b) { return sq(a.first - b.first) + sq(a.second - b.second); };

	int R = 100;
	V<pii> points; vi dist;
	map<int, map<int, int>> mp;
	for (int r = 1; r <= R; r++) dist.push_back(r * r);
	for (int x = -1000; x <= 1000; x++) {
		for (int y = -1000; y <= 1000; y++) {
			points.push_back({x, y});
			int d = sq(x) + sq(y);
			// int rr = lower_bound(all(dist), d) - dist.begin() + 1;
			int rr = upper_bound(all(dist), d) - dist.begin();
			mp[x][y] = rr;
		}
	}

	// for (int x = -10; x <= 10; x++) {
	// 	for (int y = -10; y <= 10; y++) { 
	// 		cerr << setw(2) << mp[x][y] << " ";
	// 	}
	// 	cerr << endl;
	// }




	vi fans(2 * R * R + 5);
	for (int r = 1; r <= R; r++) {
		int ans = 0;
		for (auto& [x, y] : points) {
			int d = sq(x) + sq(y);
			if (sq(r) <= d && d < sq(r + 1)) ans++;
		}
		// cerr << r << " " << ans << endl;
		fans[r] = ans;
	}
	for (int r = 1; r <= R; r++) {
		cerr << r << " " << fans[r] << " " << fans[r] - fans[r - 1] << endl;
	}


	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}