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

int dcs = 7;
void solve(int cs) {
	int n, m;
	cin >> n >> m;
	V<vi> a(n + 5, vi(m + 5)); auto b = a;
	vi rowa(n * m + 5); auto rowb = rowa;
	vi cola(n * m + 5); auto colb = cola;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			rowa[a[i][j]] = i;
			cola[a[i][j]] = j;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> b[i][j];
			rowb[b[i][j]] = i;
			colb[b[i][j]] = j;
		}
	}

	auto swapc = [&](int ca, int cb) -> void {
		for (int i = 1; i <= n; i++) {
			cola[a[i][ca]] = cb;
		}
		for (int i = 1; i <= n; i++) {
			cola[a[i][cb]] = ca;
		}
		for (int i = 1; i <= n; i++) swap(a[i][ca], a[i][cb]);
	};

	V<bool> viscol(m + 5);
	for (int x = 1; x <= n * m; x++) {
		auto ca = cola[x];
		auto cb = colb[x];
		if (ca != cb) {
			// if (!viscol[ca]) { // we don't need to do !viscol[colb[x]]
				if (cs == dcs) dbg(x, ca, cb);

				viscol[ca] = 1;
				swapc(ca, cb);
			// }
		}
	}

	auto swapr = [&](int ra, int rb) -> void {
		for (int i = 1; i <= m; i++) {
			rowa[a[ra][i]] = rb;
		}
		for (int i = 1; i <= m; i++) {
			rowa[a[rb][i]] = ra;
		}
		for (int i = 1; i <= m; i++) swap(a[ra][i], a[rb][i]);
	};

	V<bool> visrow(n + 5);
	for (int x = 1; x <= n * m; x++) {
		auto ra = rowa[x];
		auto rb = rowb[x];
		if (ra != rb) {
			// if (!visrow[ra]) { // we don't need to do !visrow[rowb[x]]
				if (cs == dcs) dbg(x, ra, rb);

				visrow[ra] = 1;
				swapr(ra, rb);
			// }
		}
	}

	bool f = 1;
	for (int i = 1; i <= n * m; i++) f &= (cola[i] == colb[i]) && (rowa[i] == rowb[i]);
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		f &= a[i][j] == b[i][j];
	// 	}
	// }
	cout << (f ? "YES" : "NO") << '\n';
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