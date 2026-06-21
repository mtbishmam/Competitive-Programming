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
	string s; cin >> s;
	int z = 0, o = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			int j = i - 1;
			while (j >= 0) {
				o += s[j] == '1';
				j--;
			}
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {
			int j = i + 1;
			while (j < n) {
				z += s[j] == '0';
				j++;
			}
			break;
		}
	}
	cout << (o + z + 1) / 2 << endl;
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