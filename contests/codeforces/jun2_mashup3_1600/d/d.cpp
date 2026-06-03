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
	int n, k, z; cin >> n >> k >> z;
	vi a(n + 5), pre(n + 5);
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];

	int ans = a[1], pos = 1;
	ans = max(ans, pre[1 + k]); // make 0 lefts
	for (int ck = 1; ck <= k; ck++) {
		int npos = pos + ck;

		int cur_score = pre[npos];

		for (int left = 1; ck + 2 * left - 1 <= k && left <= z; left++) {
			if (ck + 2 * left - 1 <= k) {
				int left_score = a[npos - 1] * left;
				int right_score = a[npos] * (left - 1);
				int moves_left = k - (ck + 2 * left - 1);
				if (moves_left > 0) 
					right_score += pre[npos - 1 + moves_left] - pre[npos - 1];
				ans = max(ans, cur_score + left_score + right_score);
			}
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