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

const int INF = 2e18; // can it cause issues?
void solve(int cs) {
	int a, n;
	cin >> a >> n;
	vi d(n); for (auto& i : d) cin >> i;
	auto chk = [&](int tries) {
		if (tries < 1) return INF;
		int ret = 0, aa = a, ten = 1;
		do {
			int lst = aa % 10, best = -1;
			auto it = lower_bound(all(d), lst);
			if (it == d.end()) {
				it--;
				best = abs(lst - *it);
			} else {
				best = *it;
				if (it != d.begin()) {
					it--;
					best = min(best, abs(lst - *it));
				}
			}
			if (best != -1) ret += abs(lst - best) * ten;
			else ret += lst * ten;
			ten *= 10;
			aa /= 10;
		} while (aa);
		return ret;
	};

	int tries = 0, aa = a;
	do {
		tries++;
		aa /= 10;

	} while (aa);
	int ans = chk(tries);
	int mxd = d.back();
	int mnd = d.front();
	int smallest = INF, largest = INF;
	for (int i = 0; i < tries - 1; i++) {
		if (!i) smallest = 0;
		smallest = smallest * 10 + mxd;
	}

	if (count(all(d), 1)) {
			largest = 1;
			for (int i = 0; i < tries; i++) {
				if (!i) largest = 0;
	
				if (sz(d) > 1 && largest == 0)
					largest = d[1];
				else largest = largest * 10 + mnd;
			}
		}
	dbg(smallest, largest);
	ans = min(ans, abs(a - smallest));
	ans = min(ans, abs(largest - a));
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