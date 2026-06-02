#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

// #define int int64_t

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int,int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

void solve(int cs) {
	int n, k; 
	cin >> n >> k;
	vi ans;
	if (k > n / 2) {
		int twos = n / 2;
		k -= twos;
		int ones = 0;
		// if n is odd
		if (n & 1) ones++, k--;
		while (k) {
			twos--;
			ones += 2;
			k--;
		}
		while (twos) ans.push_back(2), twos--;
		while (ones) ans.push_back(1), ones--;
	} else {
		if (n % 2 == 0) {
			if (n % k == 0) {
				for (int i = 0; i < k; i++) ans.push_back(n / k);
			} else {
				int n2 = n / 2;
				int rem = k - 2;
				int rem2 = rem / 2;
				int two = rem - 2 * rem2;
				int ones = 0;
				while (rem2) {
					n2 -= 2;
					ones += 2;
					rem2--;
				}
				if (two) {
					n2 -= 2;
				}
				ans.push_back(n2);
				ans.push_back(n2);
				while (ones) ans.push_back(1), ones--;
				while (two) ans.push_back(2), two--;
			}
		} else { // n is odd
			int count = n / k;
			while (count) ans.push_back(n / k), count--;
			
			if (sz(ans) > k) {
				while (sz(ans) > k) {
					int x = ans.back(); ans.pop_back(); // ans won't be empty
					ans[sz(ans) - 1] += x;
				}
			} else {
				int rem = k - sz(ans);
				while (rem) ans.push_back(1), rem--;
			}
		}
	}

	auto chk = [&](vi& ans) {
		int l = 1, sum = 0;
		for (auto& i : ans) l = lcm(l, i), sum += i;
		if (sum == k && l <= n / 2);
		else {
			dbg(ans);
			dbg(sum, l);
		}
	};

	chk(ans);

	for (auto& i : ans) cout << i << " ";
	cout << endl;
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