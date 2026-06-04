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
	int n = 1 << 10;
	for (int i = 1; i <= n; i++) {
		int x = i, moves = 0;
		do {
			if (x % 2 == 0) x /= 2;
			else x--;
			moves++;
		} while (x);

		x = i;
		string bin = "";
		while (x) {
			if (x & 1) bin += '1';
			else bin += '0';
			x /= 2;
		}
		reverse(all(bin));
		cout << i << " " << moves << " " << bin << endl;
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