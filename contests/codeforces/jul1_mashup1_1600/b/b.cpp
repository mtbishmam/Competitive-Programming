#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int,int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;
auto pw = [](int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
};

#define int int64_t
const int INF = 2e9;

void solve(int cs) {
	int n; cin >> n;
	vi a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	oset<pii> os;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		os.insert({b[i], i});
	}

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			int x = a[i] * b[j];
			os.erase({b[j], j});
			dbg(a[j], b[j]);
			for (int k = i - 1; k >= 0; k--) {
				int y = x / a[k];
				int pos = os.order_of_key({y, INF});
				int delta = sz(os) - pos;
				dbg(delta);
				ans += sz(os) - pos;
			}
			os.insert({b[j], j});
		}
	}
	cout << ans << endl;
	dbg();
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc = 1;
#ifdef DeBuG
	cin >> tc;
#endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}