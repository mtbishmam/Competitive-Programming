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
	int n, k; cin >> n >> k;
	vi a(n); for (auto& i : a) cin >> i;
	int mx_cnt = *max_element(all(a));
	int total = accumulate(all(a), (int)0);
	int total_wo_mx = total - mx_cnt;
	int ans = 1;
	int mn_decks = mx_cnt;
	if ((mn_decks - total_wo_mx % mn_decks) <= k) {
		ans = max(ans, 1 + (total_wo_mx + mn_decks - 1) / mn_decks);
	}
	// for (int mx_deck_sz = n; mx_deck_sz >= 2; mx_deck_sz--) {
	// 	if (mx_deck_sz == 1 + (total_wo_mx + mn_decks - 1) / mn_decks) {
	// 		int decks = total / mx_deck_sz;
	// 		if ((decks - total_wo_mx % decks) <= k)
	// 			ans = max(ans, 1 + mx_deck_sz);
	// 	}
	// }
	for (int decksz = 2; decksz <= n; decksz++) {
		int decks = (total + decksz - 1) / decksz;
		if (decksz - decks % decksz <= k && decks >= mn_decks) 
			ans = max(ans, decksz);
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