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
	int k; cin >> k;

	string a[2];
	a[0] = ".*.";
	a[1] = "...";
	string b[2];
	b[0] = "..";
	b[1] = "*.";
	string c[2];
	c[0] = "..";
	c[1] = ".*";

	if (k == 1) {

		cout << "YES\n";
		cout << 1 << endl;
		cout << "*" << endl;
		cout << "." << endl;

	} else if (k % 5 == 0 || k % 5 == 3) {

		int x = k / 5;
		string ans1, ans2;
		for (int i = 0, f = 0; i < x; i++, f ^= 1) {
			ans1 += a[f];
			ans2 += a[f ^ 1];
		}

		if (k % 5 == 3) {
			ans1 += c[0];
			ans2 += c[1];
		}

		cout << "YES\n";
		cout << sz(ans1) << endl;
		cout << ans1 << endl;
		cout << ans2 << endl;

	} else if (k == 6) {

		string ans1, ans2;
		ans1 = b[0] + ans1 + c[0];
		ans2 = b[1] + ans2 + c[1];

		cout << "YES\n";
		cout << sz(ans1) << endl;
		cout << ans1 << endl;
		cout << ans2 << endl;

	} else if (k >= 6 && k % 5 == 1) {

		int x = (k - 6) / 5;
		string ans1, ans2;
		for (int i = 0, f = 0; i < x; i++, f ^= 1) {
			ans1 += a[f];
			ans2 += a[f ^ 1];
		}

		ans1 = b[0] + ans1 + c[0];
		ans2 = b[1] + ans2 + c[1];

		cout << "YES\n";
		cout << sz(ans1) << endl;
		cout << ans1 << endl;
		cout << ans2 << endl;

	} else cout << "NO" << endl;
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