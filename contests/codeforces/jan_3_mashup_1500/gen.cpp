#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int, int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l, r) uniform_int_distribution<int>(l, r) (rng);

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = rand(1, 1);
	cout << t << '\n';
	while (t--) {
		int n = rand(8, 12);
		string s(n, ' ');
		for (int i = 0; i < n; i++) {
			int x = rand(1, 2);
			s[i] = '0' + (x % 2);
		}
		cout << n << '\n';
		cout << s << '\n';
	}
}
