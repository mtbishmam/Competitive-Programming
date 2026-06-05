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
	int n; cin >> n;
	int k; cin >> k;
	vi a(n); set<int> s;
	for (auto& i : a) cin >> i, s.insert(i);
	if (sz(s) == n) { // all used
		int i = 0;
		while (k) {
			cout << a[i] << " ";
			i = (i + 1) % n;
			k--;
		}
		cout << '\n';
	}	
	else { // 1 unused or 2 unused
		set<int> t;
		for (int i = 1; i <= n; i++) t.insert(i);
		for (auto x : s) t.erase(x);

		vi ans; for (auto x : t) ans.push_back(x);
		vi other;
		for (int i = n - 1; i >= 0 and sz(t) < 3; i--) {
			if (t.find(a[i]) == t.end()) {
				other.push_back(a[i]);
				t.insert(a[i]);
			}
		}
		reverse(all(other));
		for (auto& i : other) ans.push_back(i);
		// assert(sz(ans) >= 3);
		int i = 0;
		while (k) {
			cout << ans[i] << " ";
			i = (i + 1) % sz(ans);
			k--;
		}
		cout << '\n';
	}
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