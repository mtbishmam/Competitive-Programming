#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
	#define TT template <typename T
#endif

#define int int64_t

#define endl '\n'
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
TT, typename U> bool chmin(T &a, U b) { return a > b ? a = b, 1 : 0; }
TT, typename U> bool chmax(T &a, U b) { return a < b ? a = b, 1 : 0; }
TT> using V = vector<T>; using vi = V<int>;
using ll = long long; using pii=pair<int,int>;
using vb = V<bool>; using vvi = V<vi>;

void solve(int cs) {

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc = 1;
// #ifdef DeBuG
	cin >> tc;
// #endif
	for (int cs = 1; cs <= tc; cs++) solve(cs);
}
