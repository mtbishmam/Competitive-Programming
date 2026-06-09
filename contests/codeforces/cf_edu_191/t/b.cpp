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
	vi a(4 * n);

	auto chk = [&](vi& a) {
		vi idx[n + 1];
		for (int i = 0; i < 4 * n; i++)
			idx[a[i]].push_back(i);
		bool f = 1;
		for (int i = 1; i <= n; i++) {
			set<int> s;
			for (int j = 1; j < sz(idx[a[i]]); j++) {
				int dist = idx[i][j] - idx[i][j - 1];
				s.insert(dist);
			}
			f &= sz(s) == 3;
		}
		return f;
	};
	
	int i;
	for (i = 0; i < n; i++) a[i] = i + 1;
	for (int x = 1; x <= n; x++)
		for (int j = 0; j < 2; j++)
				a[i++] = x;

	vi per(n); iota(all(per), 1);
	for (int start = 0; start < n; start++) {
		int j = i, k = start;
		for (; j < 4 * n; j++, k++)
			a[j] = per[k % n];

		if(chk(a)) {
			for (auto& i : a) cout << i << " ";
			cout << endl;
			// cout << a << endl;
			break;
		}
	}

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// auto brute = [&]() {
	// 	for (int N = 2; N <= 5; N++) {
	// 		int n = N;
	// 		set<int> s[n + 1];
	// 		vi a(4 * n);
	// 		auto f = [&](int n) -> void {
	// 			bool f = 1;
	// 			for (int i = 1; i <= n; i++) f &= sz(s[i]) == 4;
	// 			if (f) {
	// 				dbg(a);
	// 				return;
	// 			}
	// 			for (int i = 1; i <= n; i++) {

	// 			}
	// 		}
	// 		dbg();
	// 	}
	// };
	// brute();

	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}