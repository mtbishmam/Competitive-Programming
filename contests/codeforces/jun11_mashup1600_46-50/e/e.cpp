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

	auto sum = [&](int x) {
		int ret = 0;
		while (x) ret += x % 10, x /= 10;
		return ret;
	};
	for (int k = 2; k <= 9; k++) {
		dbg(k);
		for (int i = 1; i <= 1000; i++) {
			if (sum(i) * k == sum(i * k)) {
				cerr << i << " " << endl;
			}
		}
		cerr << endl;
	}

	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}