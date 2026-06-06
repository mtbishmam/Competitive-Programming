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

const int INF = 1e9;
void solve(int cs) {
	int n; cin >> n;
	vi a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	map<int, vi> mp1, mp2;
	for (int i = 1, j = 0; i <= n; i++, j ^= 1) {
		if (!j) {
			mp1[a[i]].push_back(i);
			mp2[b[i]].push_back(i);
		}
		else {
			mp1[b[i]].push_back(i);
			mp2[a[i]].push_back(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sz(mp1[i]) && sz(mp2[i]));
		else continue;
		int b1 = mp1[i].back();
		int b2 = mp2[i].back();
		ans = max(ans, min(b1, b2));
	}
	for (int i = 1; i <= n; i++) {
		int c1 = INF, c2 = INF;
		if (sz(mp1[i]) >= 2) {
			int f = mp1[i].back();
			for (int j = 0; j < sz(mp1[i]) - 1; j++) {
				int s = mp1[i][j];
				if (abs(f - s) > 1) c1 = s;
			}
		}
		if (sz(mp2[i]) >= 2) {
			int f = mp2[i].back();
			for (int j = 0; j < sz(mp2[i]) - 1; j++) {
				int s = mp2[i][j];
				if (abs(f - s) > 1) c2 = s;
			}
		}
		if (c1 != INF) ans = max(ans, c1);
		if (c2 != INF) ans = max(ans, c2);
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