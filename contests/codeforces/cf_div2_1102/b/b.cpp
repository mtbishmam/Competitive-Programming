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
	if (n == 10) cout << -1 << endl;
	else if (n % 12 == 10) {
		int x = 22;		
		int y = n - 22;	
		cout << x << " " << y << endl;
	} else {
		int rem = n % 12;
		int x = 12 * (n / 12);
		assert(x + rem == n);
		cout << rem << " " << x << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto ispalin = [&](int x) {
		string s = to_string(x);
		string t = s; reverse(all(t));
		return s == t;
	};

	for (int i = 1; i <= 1000; i++) {
	// for (int i : {214, 274, 466, 658, 850})
			if (i % 12 == 10) {
				bool f = 0;


				int x = 22;
				int y = i - 22;
				if (y % 12 == 0 && ispalin(x) && y + x == i) {
					f = 1;
				}



				// for (int x = 1; x <= i; x++) {
				// 	int y = i - x;
				// 	if (y % 12 == 0 && ispalin(x) && y + x == i) {
				// 		f = 1;
				// 		cerr << i << " " << y << " " << x << endl;
				// 		break;
				// 	}
				// 	swap(x, y);
				// 	if (y % 12 == 0 && ispalin(x) && y + x == i) {
				// 		f = 1;
				// 		cerr << i << " " << y << " " << x << endl;
				// 		break;
				// 	}
				// 	swap(x, y);
				// }

				if (!f) cerr << "Impossible - " << i << endl;

		}
	}

	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}