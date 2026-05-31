#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
	#define dbg(...)
#endif

// #define int int64_t

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i=a;i<(b);++i)
using ll = long long; using pii = pair<int, int>;
using pll = pair<ll,ll>; using vi = vector<int>;
template<class T> using V = vector<T>;

int n;
string a, b;
const int N = 10;
int dp[N][2][2][2 * N]; // pos, lim, mismatch
int f(int i, int j, int k, int mis) {
	if (i == n) return 0;
	int& ret = dp[i][j][k][mis];
	if (~ret) return ret;

	ret = 1000;
	int start = (j ? a[i] - '0' : 0);
	int end = (k ? b[i] - '0' : 9);
	for (int dig = start; dig <= end; dig++) {
		bool m1 = ((a[i] - '0') == dig);
		bool m2 = ((b[i] - '0') == dig);
		ret = min(ret, m1 + m2 + f(i + 1, j && m1, k && m2, mis + m1 + m2));
	}
	return ret;
}

void solve(int cs) {
	int l, r; cin >> l >> r;
	a = to_string(l); 
	b = to_string(r);
	n = sz(a);
	memset(dp, -1, sizeof dp);
	cout << f(0, 1, 1, 0) << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) solve(cs);
	return 0;
}
