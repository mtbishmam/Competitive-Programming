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
	int n, k;
	cin >> n >> k;
	vi a(n + 1), pre(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = n, cur = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pre[mid] - pre[i - 1] <= k) {
				cur = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		if (~cur) {
			ans += cur - i + 1;
		}
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